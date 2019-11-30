/**
 * @File   : environment.ts
 * @Author : DengSir (tdaddon@163.com)
 * @Link   : https://dengsir.github.io/
 */

import * as vscode from 'vscode';
import * as path from 'path';
import * as os from 'os';
import * as _ from 'lodash';
import { once } from './decorators';

export class Fields {
    private _name: string;
    private _camelCaseName: string;
    private _PascalCaseName: string;
    private _snakeCaseName: string;
    private _kebabCaseName: string;
    private _lowerDotCaseName: string;
    private _UpperSnakeCaseName: string;

    public get name() {
        return this._name;
    }

    @once('_UpperSnakeCaseName')
    public get UpperSnakeCaseName() {
        return _.toUpper(_.snakeCase(this._name));
    }

    @once('_camelCaseName')
    public get camelCaseName() {
        return _.camelCase(this._name);
    }

    @once('_PascalCaseName')
    public get PascalCaseName() {
        return _.chain(this._name)
            .camelCase()
            .upperFirst()
            .value();
    }

    @once('_snakeCaseName')
    public get snakeCaseName() {
        return _.snakeCase(this._name);
    }

    @once('_kebabCaseName')
    public get kebabCaseName() {
        return _.kebabCase(this._name);
    }

    @once('_lowerDotCaseName')
    public get lowerDotCaseName() {
        return this.snakeCaseName.replace(/_/g, '.');
    }

    public set name(name: string) {
        this._name = name;
        this._camelCaseName = null;
        this._PascalCaseName = null;
        this._snakeCaseName = null;
        this._kebabCaseName = null;
        this._lowerDotCaseName = null;
        this._UpperSnakeCaseName = null;
    }

    public get year() {
        return new Date().getFullYear();
    }

    public get date() {
        return new Date().toLocaleDateString();
    }

    public get author(): string {
        return this.config.get('fields.author');
    }

    public get email(): string {
        return this.config.get('fields.email');
    }

    public get link(): string {
        return this.config.get('fields.link');
    }

    public get project(): string {
        return this.config.get('fields.project');
    }

    public get company(): string {
        return this.config.get('fields.company');
    }

    private get config() {
        return vscode.workspace.getConfiguration('templateGenerator');
    }
}

export class Environment {
    public targetFolderPath: string;
    public context: vscode.ExtensionContext;
    public fields: Fields = new Fields();

    public get config(): vscode.WorkspaceConfiguration {
        return vscode.workspace.getConfiguration('templateGenerator');
    }

    public get templatesFolderPath(): string {
        return this.config.get<string>('templatesPath') || path.join(os.homedir(), '.vscode/templates');
    }

    public set fileName(fileName: string) {
        this.fields.name = fileName;
    }
}

export default new Environment();
