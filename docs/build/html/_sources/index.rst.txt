.. METISSE documentation master file, created by
   sphinx-quickstart on Sat May 25 10:38:36 2024.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to METISSE's documentation!
===================================

**METISSE** is an acronym for **MET**\ hod of **I**\ nterpolation for **S**\ ingle **S**\ tar **E**\ volution. It is a code package designed for rapidly computing the evolution of stellar populations by interpolating within a set of pre-computed evolutionary tracks. The input tracks for interpolation are computed from stellar structure and evolution codes such as MESA. The input tracks must be in EEP format, meaning that significant evolutionary points like zero-age main sequence (ZAMS) should occur at the same line number across each file.  METISSE can be used as a standalone code or in conjunction with other codes for evolving populations of single and binary stars. Its special structure allows it to be easily used in codes that already use the fitting formulae-based code SSE (`Hurley et al. 2000 <https://ui.adsabs.harvard.edu/abs/2000MNRAS.315..543H/abstract>`_ ).


Check out the following sections for further information.


.. toctree::
   :maxdepth: 1

   citation
   contents
   download
   glossary
   input_files
   usage_other
   usage_standalone
   using_custom_input_tracks
   workflow
