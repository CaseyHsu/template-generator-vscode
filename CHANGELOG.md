# Change Log
All notable changes to the "template-generator-vscode" extension will be documented in this file.

Check [Keep a Changelog](http://keepachangelog.com/) for recommendations on how to structure this file.

## [0.4.5]
### Added
 - Flat folder templates: a folder named `{__delete__.<label>}` expands its files into the target folder
 - `C module (.c + .h)` template
 - `C++ class (.hpp + .cpp)` template with the same init/reset/run interface as the C modules
 - MATLAB templates: function, parameter script, C-MEX S-function and MEX function wrappers for C modules
 - `project_types (C types).h` template: portable `int16`/`Uint16`/`float32`/... types on `<stdint.h>`
### Changed
 - C templates use a handle style (`<Name>_Params`, `<Name>_Obj`, `<Name>_init/reset/run`) instead of `EXTERN_<NAME>` globals
 - C headers include `project_types.h` instead of `F28x_Project.h`
### Fixed
 - C: include guard / `_SRC` macros no longer use reserved `__` identifiers; `extern "C"` guard for C++; template function returns a value
 - VHDL: drop non-standard `STD_LOGIC_UNSIGNED`, make `UNISIM` optional, substitute the process label, file name matches entity name
 - Python: Python 3 shebang, remove stray `.html` in `@Project`, add docstring and `main` guard
 - Error messages now show conflicting targets and the underlying failure

## [0.4.4]
### Added
 - project name and company name

## [0.4.3]
### Added
 - upper snake case name

## [Unreleased]
- Initial release

## [0.4.0]
### Added
- field {\_\_delete\_\_}

## [0.3.0]
### Added
- camel case
- pascal case
- snake case
- kebab case
- lower dot case
