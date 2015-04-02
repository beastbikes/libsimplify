{
    'target_defaults' : {
        'default_configuration' : 'Debug',
        'configurations' : {
            'Debug' : {
                'defines' : [ ],
                'msvs_settings' : {
                    'VCCLCompilerTool' : {
                        'RuntimeLibrary' : 1,
                    },
                },
            },
            'Release' : {
                'defines' : [ 'NDEBUG' ],
                'msvs_settings' : {
                    'VCCLCompilerTool' : {
                        'RuntimeLibrary' : 0,
                    },
                },
            }
        },
        'msvs_settings' : {
            'VCLinkerTool' : {
                'GenerateDebugInformation' : 'true',
            },
        },
    },
    'targets' : [{
        'target_name' : 'libsimplify',
        'product_prefix' : 'lib',
        'type' : 'static_library',
        'include_dirs' : [
            'include',
        ],
        'sources' : [
            'src/simplify.c',
        ],
    }, {
        'target_name' : 'simplify',
        'type' : 'executable',
        'include_dirs' : [
            'include',
        ],
        'sources' : [
            'src/main.c',
        ],
        'dependencies' : [
            'libsimplify',
        ],
    }],
}
