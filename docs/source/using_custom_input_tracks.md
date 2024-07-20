# Custom input tracks

METISSE can use any set of tracks computed with MESA or other stellar evolution codes. Before use in METISSE, the input tracks need to be converted to EEP format, ensuring that key evolutionary points, such as the zero-age main sequence (ZAMS), are aligned across all files. 

Details about EEP tracks are provided through the `&metallicity_controls` inlist, also known as the `metallicity file`. Apart from the metallicity files, users are also required to specify the format of the input files through the `&format_controls` inlist. 

*While different sets of EEP tracks can share the same format file, they must have separate metallicity files.*

For the most up-to-date variable names and their default values refer to [metallicity_defaults](https://github.com/TeamMETISSE/METISSE/blob/develop/src/defaults/metallicity_defaults.inc)   and [format_defaults](https://github.com/TeamMETISSE/METISSE/blob/develop/src/defaults/format_defaults.inc). 


## metallicity_controls

| Parameter            | Description     |
|----------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| INPUT_FILES_DIR      | Location of the folder containing input files for a given metallicity                                                                                               |
| Z_files              | Metallicity of input tracks. Used to cross-check against input Z to avoid mistakes.                                                              |
| format_file          | Details about the file structure (see format_defaults.dat). Empty string will raise an error.                                                                         |
| read_all_columns     | If false, METISSE only interpolates in essential columns and additional columns specified in `format_file`. <br> If true, interpolates in all columns of input files, which is slow.                                                                        |
| extra_columns        | Extra columns to be used for interpolation if `read_all_columns` is false. <br> Up to 100 column names can be listed as strings, separated by commas.                    |
| extra_columns_file   | Alternatively, list extra column names in a text file (one per line) in the `extra_columns_file` and provide path of the file here.                                                             |
| Z_H                  | Hydrogen abundance. Default is SSE formulae. If < 0, calculated from Z as 0.76 - 3*Z.                                                                                |
| Z_He                 | Helium abundance. Default is SSE formulae. If < 0, calculated from Z as 0.24 + 2*Z. |



```

INPUT_FILES_DIR = ''
Z_files = -1.0
format_file = ''

read_all_columns = .false.

extra_columns = ''
extra_columns_file = ''

Z_H = -1.0
Z_He = -1.0

```

Note:

1. For binary evolution calculations, ONLY default columns are used, irrespective of whether `read_all_columns` is true or not. Quantities interpolated using any other columns are currently discarded.

2. The `extra_columns` option only useful for single-star evolution calculations with implicit mass loss. The interpolated quantities are printed in MIST-style files if `write_eep_file` is set to true.


 `&metallicity_controls` also contain option to provide user-defined values of mass cutoff parameters or zparameters. If < 0, these values are calculated by the code. 

| Parameter            | Description     |
|----------------------|----------------------------------------------------------|
| Mhook                | Mass below which hook doesn't appear on MS.|
| Mhef                 | Mass above which He ignition occurs non-degenerately.              |
| Mfgb                 | Mass above which He ignition occurs on the HG.                     |
| Mup                  | Mass below which C/O ignition doesn't occur.                    |
| Mec                  | Mass above which C ignites in the centre. |                 
| Mextra               | Extra mass cutoff, if any.  |

```
Mhook = -1.0
Mhef = -1.0
Mfgb = -1.0
Mup = -1.0
Mec = -1.0
Mextra = -1.0   
```


## format_controls


| Parameter               | Description     |
|-------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| file_extension          | File extension of the input files (e.g., '.eep', '.dat').                                                                                                                                                                                                |
| read_eep_files          | Set to true only for [MIST-style](https://waps.cfa.harvard.edu/MIST/model_grids.html) files . <br> If true, extra_char, total_cols, and other information can be read directly from files; <br> set to false for other types of files.                                                                                                                                         |
| header_location         | Line number where column names are listed in the input files. <br> Set to <=0 if the input files do not contain column names; specify `column_name_file` for such cases.                                                                                                                           |
| extra_char              | Any extra character present in the header line (if any).                                                                                                                                                                                                                                                                                                  |
| column_name_file        | File containing column names (one per line) if `header_location` <= 0 <br> and column names cannot be determined from input files.                                                                                             |
| total_cols              | Total number of columns in the input files.                                                                            |

```

file_extension = ''
read_eep_files = .false.
header_location = -1
extra_char = ''
column_name_file = ''
total_cols = -1

```


    
### Essential columns

Use this section to name some important columns, as columns might have different names. The code will stop if it cannot find these columns unless stated in the description. Make sure that the units are correct.


| Parameter               | Description     |
|-------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| age_colname             | Column name for age in years.                                                                       |
| mass_colname            | Column name for star's total mass in solar units.                                                                                                                               |
| log_L_colname           | Column name for log10 of luminosity in solar units. Used if `Lum_colname` is not provided.                                                                                    |
| Lum_colname             | Column name for stellar luminosity in solar units. Used only if `log_L_colname` is not supplied.                                                                  |
| log_R_colname           | Column name for log10 of radius in solar units. Used if `Radius_colname` is not provided.                                                                    |
| Radius_colname          | Column name for stellar radius in solar units. Used only if `log_R_colname` is not supplied.                                                                   |
| he_core_mass            | Column name for mass of He enriched/H depleted core in solar units.                                                                                                            |
| co_core_mass            | Column name for mass of C enriched/He depleted core in solar units.                               |



```
age_colname = ''
mass_colname = ''
log_L_colname = ''
Lum_colname = ''
log_R_colname = ''
Radius_colname = ''
he_core_mass = ''
co_core_mass = ''

```

### Additional columns 

METISSE will raise error but not stop if these column names are not provided. However, it will revert to using SSE formulae where needed. 



| Parameter               | Description     |
|-------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| he_core_radius          | Column name for radius of He enriched/H depleted core in solar units (cannot use log).                                                                                                                                                                      |
| co_core_radius          | Column name for radius of C enriched/He depleted core in solar units (cannot use log).                                                                         |
| mass_conv_envelope      | Column name for mass of the convective envelope in solar units.                                                                                               |
| radius_conv_envelope    | Column name for radius of the convective envelope in solar units.                                                                                              |
| log_T_colname           | Column name for log10 of surface temperature in K. Used if `Teff_colname` is not provided.                                                                    |
| Teff_colname            | Column name for surface temperature in K. Used only if `log_T_colname` is not supplied.                                                                      |
| log_Tc                  | Column name for central temperature in log units.                                                                                                            |
| he4_mass_frac           | Column name for helium-4 mass fraction at centre.                                                                                                            |
| c12_mass_frac           | Column name for carbon-12 mass fraction at centre.                                                                                                           |
| o16_mass_frac           | Column name for oxygen-16 mass fraction at centre.     |


```
he_core_radius = ''    
co_core_radius = ''
mass_conv_envelope = ''
radius_conv_envelope = ''
log_T_colname = ''
Teff_colname = ''
log_Tc = ''
he4_mass_frac = ''
c12_mass_frac = ''
o16_mass_frac = ''
```
### EEP details for hydrogen stars



| Parameter               | Description     |
|-------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| PreMS_EEP               | EEP/line number for Pre-Main Sequence phase.                                                                                                                  |
| ZAMS_EEP                | EEP/line number for Zero Age Main Sequence.                                                                                                                  |
| IAMS_EEP                | EEP/line number for Initial-Age Main Sequence.                                                                                                                 |
| TAMS_EEP                | EEP/line number for Terminal-Age Main Sequence.                                                                                                                 |
| BGB_EEP                 | EEP/line number for Base of Giant Branch.                         |
| cHeIgnition_EEP         | EEP/line number for central Helium Ignition.                                                                                                                  |
| cHeBurn_EEP             | EEP/line number for central Helium Burning.                                                                                                                   |
| TA_cHeB_EEP             | EEP/line number for Thermally-Pulsing Asymptotic Giant Branch.                                                                                                |
| TPAGB_EEP               | EEP/line number for Terminal-Pulsing Asymptotic Giant Branch.                                                                                                                                                                                            |
| cCBurn_EEP              | EEP/line number for central Carbon Burning.                                                                                                                    |
| post_AGB_EEP            | EEP/line number for Post-Asymptotic Giant Branch.                                                                                                            |                                                                    |
| Extra_EEP1              | Additional EEP/line number (optional).                                                                                                                        |
| Extra_EEP2              | Additional EEP/line number (optional).                                                                                                                        |
| Extra_EEP3              | Additional EEP/line number (optional).                                                                                                                          |
| Initial_EEP             | EEP/line number to start reading files; if < 0, uses ZAMS_EEP.                                                                                                                                                                      |
| Final_EEP               | EEP/line number to stop reading files; if < 0, uses maximum of listed EEPs.                                                                                                                     


```
PreMS_EEP = -1
ZAMS_EEP = -1
IAMS_EEP = -1
TAMS_EEP = -1
BGB_EEP = -1
cHeIgnition_EEP = -1
cHeBurn_EEP = -1
TA_cHeB_EEP = -1
TPAGB_EEP = -1
cCBurn_EEP = -1
post_AGB_EEP = -1

Extra_EEP1 = -1
Extra_EEP2= -1
Extra_EEP3 = -1

Initial_EEP = -1
Final_EEP = -1

```


### EEP details for stripped/ naked helium stars

| Parameter               | Description     |
|-------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| ZAMS_HE_EEP             | EEP/line number for Zero Age Main Sequence of Helium stars.                                                                                               |
| TAMS_HE_EEP             | EEP/line number for Terminal Age Main Sequence of Helium stars.                                                                                             |
| GB_HE_EEP               | EEP/line number for Base of Giant Branch of Helium stars.                                                                                                   |
| cCBurn_HE_EEP           | EEP/line number for central Carbon Burning of Helium stars .                                                                                                 |
| post_AGB_HE_EEP         | EEP/line number for Post-Asymptotic Giant Branch of Helium stars.                                                                                            |

```
ZAMS_HE_EEP = -1
TAMS_HE_EEP = -1
GB_HE_EEP = -1
cCBurn_HE_EEP = -1
post_AGB_HE_EEP = -1 
```


### How to deal with the incomplete tracks

METISSE uses two to four adjacent mass tracks to create a new stellar mass track. If any of these tracks is incomplete, the interpolated track will also be incomplete. This section explains how to identify incomplete tracks and attempt to fill in the missing data. 

*(In an ideal world, we wouldn't need this section, but unfortunately, the world is not ideal, and incomplete or incorrect data is more common in datasets than we'd like to believe.)*


| Parameter               | Description     |
|-------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| low_mass_final_eep      | Final EEP/line number for stars with M < Mec when figuring out and fixing incomplete tracks.                                                                    |
| high_mass_final_eep     | Final EEP/line number for stars with M >= Mec when figuring out and fixing incomplete tracks.                                                                      |
| fix_track               | If true, METISSE relaxes criteria for finding neighboring tracks to fix incomplete tracks.                                                                     |
| lookup_index            | Determines range for searching neighboring tracks when fixing incomplete tracks. <br> The range is initial_mass - (initial_mass * lookup_index) and initial_mass + (initial_mass * lookup_index)    |


```    

low_mass_final_eep = -1
high_mass_final_eep = -1
fix_track = .true.
lookup_index = 1.0

```