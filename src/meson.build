src_inc = include_directories('.')

deps = [
  glib_dep,
  gio_dep,
  gtk_dep,
  gwords_dep,
]

sources = files(
  'gmfl-application.c',
  'gmfl-log.c',
  'gmfl-window.c',
  'main.c',
)


##############
# GResources #
##############

sources += gnome.compile_resources(
  'gmfl-resources',
  gresource,
  source_dir: data_dir,
  c_name: 'gmfl',
  dependencies: resource_data,
  export: true
)


################
# Debug macros #
################

debug_conf = configuration_data()
debug_conf.set('BUGREPORT_URL', 'https://github.com/GeorgesStavracas/gmafell' + meson.project_name())
debug_conf.set10('ENABLE_TRACING', enable_tracing)

sources += configure_file(
  input: 'gmfl-debug.h.in',
  output: 'gmfl-debug.h',
  configuration: debug_conf
)


##############
# Executable #
##############

executable(
  meson.project_name(),
  sources,
  include_directories: src_inc,
  dependencies: deps,
  install: true,
  install_dir: gmafell_bindir
)
