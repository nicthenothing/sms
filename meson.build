#Copyright siz-tel PRIVATE CODE,
#If you are reading this and you are not a part of siz-tel
#SO واگذارت میکنم به دو دست بریده ی ابلفضل

libdiameter_sgd_sources = files('''
    ogs-diameter-sgd.h
    message.h
    dict.c
    message.c
'''.split())

libdiameter_sgd_inc = include_directories('.')

libdiameter_sgd = library('ogsdiameter-sgd',
    sources : libdiameter_sgd_sources,
    version : libogslib_version,
    c_args : libdiameter_common_cc_flags,
    include_directories : libdiameter_sgd_inc,
    #todo maybe need to edit
    dependencies : libdiameter_common_dep,
    install : true)

libdiameter_sgd = declare_dependency(
    link_with : libdiameter_sgd,
    include_directories : libdiameter_sgd_inc,
    #todo maybe need to edit
    dependencies : libdiameter_common_dep)