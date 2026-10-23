# Template Generator

This extension helps in creating files and folders easily from defined templates.

a Files/Folders template for vscode,fork from https://github.com/DengSir/template-generator-vscode.git

## Features

* File template support
* Folder template support

## Usages

### Commands

* `Files: New File from Template`
* `Template: Open Templates Folder`

### Default templates path

* Windows : %HOMEPATH%/.vscode/templates
* Linux : ~/.vscode/templates
* Mac : ~/.vscode/templates

### Custom fields

* `{__name__}` : file name
* `{__author__}` : author
* `{__email__}` : email
* `{__link__}` : link
* `{__project__}` : project name
* `{__company__}` : copyright name
* `{__date__}` : create local date
* `{__year__}` : create year
* `{__camelCaseName__}` : camelCaseFileName
* `{__PascalCaseName__}` : PascalCaseFileName
* `{__snakeCaseName__}` : snake_case_file_name
* `{__kebabCaseName__}` : kebab-case-file-name
* `{__lowerDotCaseName__}` : lower.dot.case.file.name
* `{__UpperSnakeCaseName__}` : UPPER_SNAKE_CASE_FILE_NAME
* `{__delete__}` : empty string

You can define the name displayed on the template selector, like:

* `{__name__.python}.py`

### Multi-file templates without a wrapping folder

A folder template named only `{__delete__.<label>}` expands its files directly into the target folder,
e.g. a C source/header pair:

```
{__delete__.C module (.c + .h)}/
├── {__name__}.c
└── {__name__}.h
```

Creation is refused if any of the target files already exists.

### C module templates

The C templates use a handle (object) style instead of exported globals:

```c
static SpeedCtrl_Obj axis1;            /* one instance per axis, no malloc */
SpeedCtrl_init(&axis1, &params);
out = SpeedCtrl_run(&axis1, input);    /* e.g. from the control ISR */
```

Module headers include only `project_types.h` (fixed-width types on `<stdint.h>`), not device
headers, so the same module compiles on the target and on a host PC for unit tests.
`project_types.h` uses the same `DSP28_DATA_TYPES` guard as the TI C2000 device headers, so
both can be included in either order.

### Example

File name :

`{__name__.python}.py`

File content :

```
#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# {__name__}.py
# @Project : {__project__}
# @Author  : {__author__} ({__email__})
# @Link    : {__link__}
# @Date    : {__date__}

```

[More Example](https://github.com/DengSir/template-generator-example)

### Default templates

* `c.c` / `h.h`
* `C module (.c + .h)`
* `project_types (C types).h` (always creates `project_types.h`; the name input is ignored)
* `html.html`
* `javascript.js`
* `lua.lua`
* `python.py`
* `python Folder`
* `typescript.ts`
* `vhd.vhd` (file name follows the PascalCase entity name)

## Extension Settings

This extension contributes the following settings:

#### Settings

* `templateGenerator.templatesPath` : Where do you want to save the template Settings
* `templateGenerator.openFileByFileTemplate` : Open the file when the file is created by file template
* `templateGenerator.openFilesByFolderTemplate` : Open all files when the files is created by folder template

#### Fileds

* `templateGenerator.fields.author` : Custom fields of Template Generator: author
* `templateGenerator.fields.email` : Custom fields of Template Generator: email
* `templateGenerator.fields.link` : Custom fields of Template Generator: link
* `templateGenerator.fields.project` : Custom fields of Template Generator: project
* `templateGenerator.fields.company` : Custom fields of Template Generator: company

## Known Issues

## Release Notes

### For more information

**Enjoy!**
