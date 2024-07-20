# Acronyms and definitions

The following list provides details of all the acronyms and definitiosn used throughout this documentation. 

## Stellar phases

| Acronym | Evolutionary State                              |
|-------|-------------------------------------------------|
| MS    | Main Sequence       |
| HG     | Hertzsprung Gap                                  |
| RGB     | Red Giant Branch                               |
| cHeB     | Core Helium Burning                              |
| AGB     | Asymptotic Giant Branch              |
| TPAGB     | Thermally Pulsing Asymptotic Giant Branch                             |     


## Stellar tracks versus models

We use the term ‘stellar
model’ to mean the same as the sequence of stellar models
or a stellar track while the term ‘set of stellar models’ or
‘set of stellar tracks’ means evolutionary tracks of stars with
different initial masses but the same metallicity.


## File types:

*SSE-style file:*

These files have a file structure similar to the popular [SSE](https://astronomy.swin.edu.au/~jhurley/bsedload.html) code.



*MIST-style file:*

The file structure follows the same format used in the files from the [MIST](https://waps.cfa.harvard.edu/MIST/model_grids.html) project.


## Metallicity File

This file contains information about the input tracks for a specific metallicity, including the path to the folder containing the EEP tracks, the metallicity value, and other relevant information and metadata.


## Format files


The format file contains information on how to read files, such as header location, important EEPs, and certain column names. 


## Fortran namelists

Namelists offer a convenient method for inputting data into Fortran programs. Each entry within a namelist follows this structure:

```
name = value ! comment
```

Values are provided using typical Fortran syntax. `SSE_input_controls` , `METISSE_input_controls`, `metallicity_controls` and `format_controls` are Fortran namelists, so comments (anything after the exclamation mark symbol!) and whitespaces can be used freely. Characters are also case-insensitive. It is important to ensure that there is a blank line at the end of the file following the `/` symbol.


