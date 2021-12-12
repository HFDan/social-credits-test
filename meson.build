project('socialcredittest', 'cpp', default_options : ['c_std=c11', 'cpp_std=c++17'])
thread_dep = dependency('threads')

if host_machine.system() == 'windows'
add_global_arguments('-DWIN32', language : 'c')
add_global_arguments('-DWIN32', language : 'cpp')
elif host_machine.system() == 'linux' or host_machine.system() == 'darwin'
add_global_arguments('-DUNIX', language: 'c')
add_global_arguments('-DUNIX', language: 'cpp')
endif

executable('socialcredits', ['main.cpp', 'socialcredits.cpp', 'color.cpp'], dependencies: thread_dep)
