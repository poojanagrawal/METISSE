# Input files

Inputs to METISSE are provided using the following [Fortran namelists](acronyms_definitions.md#fortran-namelists):



## SSE input controls

`SSE_input_controls` is holds input parameters describing the initial conditions of the star/stellar populations. For the most up-to-date variable names and their default values refer to [main_defaults](https://github.com/TeamMETISSE/METISSE/blob/develop/src/defaults/main_defaults.inc).

:::{Note}
`main.input` is **only** read in METISSE's standalone mode. 
When METISSE is used with other codes, the input parameters from the overlying code are used.
:::



### EVOLUTION CONTROLS

| Variable name        | Description  |
|----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| read_mass_from_file  | <br> Logical, if `read_mass_from_file = .true.` provide masses in a text file (one per line) <br> listed in the `input_mass_file`. Use `number_of_tracks` to specify how many masses to use.<br> If `read_mass_from_file = .false.`, use `min_mass` (lower limit), `max_mass` (upper limit), <br> and `number_of_tracks` for uniformly distributed masses between the limits.<br> To evolve a single star set `number_of_tracks = 1` and `min_mass`, ignore `max_mass`. <br> Default is false.                                                                                                                                                |
| input_mass_file      | Location of the input mass file if `read_mass_from_file = .true.`                                                                                       |
| number_of_tracks     | Number of stars to be evolved.                                                                                                                             |
| max_mass             | Upper limit for mass range if `read_mass_from_file = .false.` and `number_of_tracks > 1`                                                                                                                                                               |
| min_mass             | Lower limit for mass range if `read_mass_from_file = .false.`                                                                                              |
| initial_Z            | Initial metallicity                                                                                                                                        |
| max_age              | Maximum age in Megayears    |


```
! EVOLUTION CONTROLS
read_mass_from_file = .false.      
input_mass_file = ''
number_of_tracks = 0
max_mass = -1.0
min_mass = -1.0
initial_Z = -1.0
max_age = -1.0   
```

    
### REMNANT CONTROLS



| Variable name                 | Description |
|-------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| WD_mass_scheme                | White Dwarf (WD) luminosity calculation method:<br>(1) "Mestel" - [Shapiro S. L., Teukolsky S. A., 1983](https://ui.adsabs.harvard.edu/abs/1983bhwd.book.....S/abstract)<br>(2) "Modified_mestel" - [Hurley J. R., Shara M. M., 2003, ApJ, 589, 179](https://iopscience.iop.org/article/10.1086/374637)                                                                                               |
| use_initial_final_mass_relation | Logical, if true use the initial final mass relation for White Dwarfs (citation needed). <br> Default is false.                                                                                               |
| BHNS_mass_scheme              | Neutron Star/Black Hole (NS/BH) type and mass calculation method:<br>(1) "original_SSE" - Default SSE<br>(2) "Belczynski2002" - [Belczynski et al. 2002, ApJ, 572, 407](https://iopscience.iop.org/article/10.1086/340304)<br>(3) "Belczynski2008" - [Belczynski et al. 2008, ApJS, 174, 223](https://iopscience.iop.org/article/10.1086/521026)<br>(4) "Eldridge_Tout2004" - [Eldridge J. J., Tout C. A., 2004, MNRAS, 353, 87](https://ui.adsabs.harvard.edu/abs/2004MNRAS.353...87E/abstract)                                                                                              |
| max_NS_mass | Maximum neutron star mass. Default is 3.0 <br> Recommended 1.8 for BHNS_mass_scheme = "original_SSE", 3.0 otherwise.                                                                                               |
| allow_electron_capture | Logical, allow electron capture supernovae if true. <br> Default is true.|        

```
! REMNANT CONTROLS 
WD_mass_scheme = 'Modified_mestel'
use_initial_final_mass_relation = .false.       
BHNS_mass_scheme = 'Belczynski2008'
max_NS_mass = 3.d0
allow_electron_capture = .true.  
```
### TIMESTEP CONTROLS

Similar to SSE, METISSE determines timesteps as the fractions of the time spent in a phase.


| Variable name                 | Description |
|-------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| pts_1                         | 95% of MS, HeMS. Default is 0.05
| pts_2                         | last 5% of MS, cHeBurn, HeHG, HeGB. Default is 0.01
| pts_3                         | HG, RGB, EAGB, TPAGB. Default is 0.02

```
! TIMESTEP CONTROLS
pts_1 = 0.05
pts_2 = 0.01
pts_3 = 0.02
```

### OTHER CONTROLS
| Variable name                 | Description |
|-------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| write_track_to_file           | <br> Generate an SSE-style output file (file ending in .dat) at the END of the evolution. <br> Default is false|

```

write_output_to_file = .false.
```


## METISSE input controls

`METISSE_input_controls` contains input parameters specific to METISSE. 

For the most up-to-date variable names and their default values refer to [metisse_defaults](https://github.com/TeamMETISSE/METISSE/blob/develop/src/defaults/metisse_defaults.inc). 


### TRACK CONTROLS


| Variable name   | Description  |
|-----------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| tracks_dir      | <br> Path for providing location of the metallicity files. Metallicity files end with *metallicity.in* and  <br> contain details about sets of input tracks for hydrogen stars,  including their metallicity values and other metadata. <br> METISSE will stop and raise error if `tracks_dir` is an empty string.                                                                                                                                       |
| tracks_dir_he   | <br> Similar to `tracks_dir` but for providing details about sets of input tracks for naked helium/stripped stars. <br>If `tracks_dir_he` is an empty string, SSE fitting formulae or naked helium stars are used.                                                                                                                                      |
| Z_accuracy_limit| <br> METISSE checks for a match in metallicity based on the condition <br> `(abs(Z_input - Z_required) / MIN(Z_input, Z_required)) > Z_accuracy_limit`, <br> where `Z_input` is the metallicity value of the tracks (from the metallicity file)<br>   and `Z_required` is the desired value. The default `Z_accuracy_limit` is set to `1d-2`.                                                                                                        |

```
! TRACK CONTROLS
tracks_dir = ''
tracks_dir_he = ''
Z_accuracy_limit = 1d-2
```

### OUTPUT CONTROLS
| Variable name                 | Description  |
|-------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| verbose                       | <br> If true, `verbose` prints useful details when reading the input tracks. <br />Default is false.| 
| write_eep_file                | <br> Generate MIST style output file at EVERY step of mass interpolation.<br /> Useful for debugging and single star evolution calculations with implicit mass loss. <br />Default is false.|
| write_error_to_file           | <br> If true, error messages from METISSE are written to a file named fort.99 <br />otherwise they are printed on screen (does NOT apply to errors during reading input files). <br />Default is true.|

```
! OUTPUT CONTROLS
verbose = .false. 
write_eep_file = .false.		
write_error_to_file = .true.
```
    
### MISCELLANEOUS CONTROLS
| Variable name                 | Description  |
|-------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| mass_accuracy_limit           | <br> Skip interpolation in mass if there is already an input track with <br> initial_mass within the `mass_accuracy_limit`. Default is 1d-4|
| construct_wd_track            | <br> Artificially construct the track between TPAGB phase <br> or tip of the AGB to the WD cooling track (for low-mass stars).  <br>It is useful if input tracks do not contain this phase but can be used otherwise too. <br>Default is true.| 

```
! MISCELLANEOUS CONTROLS
mass_accuracy_limit = 1d-4
construct_wd_track = .true.
```



