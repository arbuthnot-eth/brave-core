file(GLOB analysis_HEADERS *.h)
set(analysis_SOURCES
  cfg.cpp
  sign-lattice.cpp
  ${analysis_HEADERS}
)
add_library(analysis OBJECT ${analysis_SOURCES})
