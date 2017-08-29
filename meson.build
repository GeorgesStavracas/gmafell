project(
  'gmafell',
  'c',
  version : '0.1.0',
  license : 'GPL3+',
  default_options : ['buildtype=debugoptimized', 'warning_level=1'],
  meson_version : '>=0.42'
)

gmafell_version = meson.project_version()
varr = gmafell_version.split('.')
gmafell_major_version = varr[0].to_int()
gmafell_minor_version = varr[1].to_int()
gmafell_micro_version = varr[2].to_int()


###############
# Directories #
###############

gmafell_prefix = get_option('prefix')
gmafell_bindir = join_paths(gmafell_prefix, get_option('bindir'))
data_dir = join_paths(meson.source_root(), 'data')

################
# Dependencies #
################

glib_ver = '>= 2.45.8'
glib_dep = dependency('glib-2.0', version : glib_ver)
gio_dep = dependency('gio-2.0', version : glib_ver)
gtk_dep = dependency('gtk+-3.0', version : '>= 3.22.0')
gwords_dep = dependency('gwords-0', version : '>= 0.1')

gnome = import('gnome')
i18n = import('i18n')


###########
# Options #
###########

gmafell_debug = gmafell_minor_version.is_odd() or buildtype.contains('debug')

enable_tracing = get_option('enable-tracing')


############
# config.h #
############

conf = configuration_data()
conf.set('GMFL_MAJOR_VERSION', gmafell_major_version)
conf.set('GMFL_MINOR_VERSION', gmafell_minor_version)
conf.set('GMFL_MICRO_VERSION', gmafell_micro_version)
conf.set_quoted('PACKAGE_VERSION', gmafell_version)
conf.set_quoted('GETTEXT_PACKAGE', meson.project_name())
conf.set_quoted('LOCALEDIR', get_option('localedir'))
conf.set_quoted('LOCALSTATEDIR', get_option('localstatedir'))

configure_file(
         output: 'config.h',
  configuration: conf
)

add_global_arguments('-DGMFL_COMPILATION', language : 'c')


###########
# Subdirs #
###########

subdir('data')
subdir('po')
subdir('src')


##########
# Output #
##########

output = '\n\n     GMafell ' + gmafell_version + '\n'
output += '      =========================\n\n'
output += '          Source ...........................  ' + meson.source_root() + '\n'
output += '          Prefix ...........................  ' + gmafell_prefix + '\n'
output += '          Compiler .........................  ' + meson.get_compiler('c').get_id() + '\n\n'
output += '      Development options\n'
output += '          Enable Debug: ....................  ' + gmafell_debug.to_string() + '\n'
output += '          Enable Tracing: ..................  ' + enable_tracing.to_string() + '\n'
output += '      Now type "ninja -C ' + meson.build_root() + '" to build ' + meson.project_name() + '\n\n'

message(output)
