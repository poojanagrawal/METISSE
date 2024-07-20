# Workflow

Here is a flowchart describing the workflow of METISSE:




![METISSE's flowchart](METISSE_flowchart.png)



<!-- # module details

All kinds tracks in METISSE are stored in Fortran's derived data type (think class in python/c++) called track  which is defined in track_support. It mostly has two components : a header part (e.g. initial_mass, ntrack etc.)  and an array tr which stores file data as an array.  xa, sa, sa_he and tarr  all belong to this type.
xa is a temporary variable. We read all the input data through it and, filter whatever we need and store it either in sa (hydrogen tracks) or sa_he (helium tracks).
tarr is special; it is where we store interpolated tracks. It also makes use some other feature of track such as pars which stores stellar parameters at any given age.

For reading input data in xa, we have two kind of functions. One is specific to filetype used by Choi et al. 2016 (MIST-EEP files) and other is more general. However they both do the same thing; read file and store header data and tr for each element of xa.  However, at first call they also identify various columns and their locations, controlled by the variable get_columns. These columns are identified by calling the subroutine get_named_columns. After xa is read, tracks are checked for errors through check_tracks . For complete tracks, we check here if any column needs to be converted to log within this subroutine.  We next find zparameters/mcrit/mcutoff using xa (See METISSE's 2020 paper for their definition). Finally we use copy_and_deallocatex to store only the relevant information in sa or sa_he.  We also do other some other checks and set what we call key_cols , where essential columns get reassigned to match to reduced array format of sa/sa_he. -->