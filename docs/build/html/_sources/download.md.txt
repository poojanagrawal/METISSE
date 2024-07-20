
# Downloading METISSE

## Prequisites

METISSE requires a fortran installation specifically gfortran that comes with gcc/6.4.0 and more recent versions.
Checkout [this page](https://fortran-lang.org/learn/os_setup/install_gfortran/) if you need help installing gfortran. 


## Code
The code package for METISSE is available at this [GitHub Repository](https://github.com/TeamMETISSE/METISSE).


## Input tracks

In addition to the code package, METISSE also requires a set of EEP tracks with a given metallicity to interpolate a stellar track for the same metallicity and a specific mass. 
Information about each set of EEP tracks is provided through two Fortran namelists called `metallicity file` and `format file`. 

The location of the folder containing metallicity files should be given as input to METISSE. This and other inputs should be provided to METISSE depending on how METISSE is used (in standalone mode or conjunction with other codes).

*EEP tracks for a range of mass and metallicity, computed using MESA, and ready for use with METISSE can be downloaded from this link.*



