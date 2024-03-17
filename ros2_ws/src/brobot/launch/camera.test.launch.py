from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument as LaunchArg
from launch.actions import OpaqueFunction
from launch.substitutions import LaunchConfiguration as LaunchConfig
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    ld = LaunchDescription()
    cam_node = Node(package='spinnaker_camera_driver',
                executable='camera_driver_node',
                output='screen',
                name='left_camera',
                parameters=[{'camera_name':'camera'},
                            {'camera_type':'blackfly_s'},
                            {'serial_number':'23185348'},
                            {'parameter_file':'/ros2_ws/src/brobot/src/config/camera_parameters.yaml'},
                            {'debug': False},
                            {'compute_brightness': False},
                            {'adjust_timestamp': True},
                            {'dump_node_map': False},
                            #set parameters defined in blackfly_s.yaml
                            {'gain_auto': 'Continuous'},
                            {'pixel_format': 'BayerRG8'},
                            {'exposure_auto': 'Continuous'},
                            {'frame_rate_auto': 'Off'},
                            {'frame_rate': 10.0},
                            {'frame_rate_enable': True},
                            {'buffer_queue_size': 1},
                            {'trigger_mode': 'Off'},
                            {'chunk_mode_active': True},
                            {'chunk_selector_frame_id': 'FrameID'},
                            {'chunk_enable_frame_id': True},
                            {'chunk_selector_exposure_time': 'ExposureTime'},
                            {'chunk_enable_exposure_time': True},
                            {'chunk_selector_gain': 'Gain'},
                            {'chunk_enable_gain': True},
                            {'chunk_selector_timestamp': 'Timestamp'},
                            {'chunk_enable_timestamp': True}],
                remappings=[('~/control', '/exposure_control/control'), ])
    
    #For some reason the GUI window is blocked in the launch file
    # view_finder = Node(package='image_view',
    #                    executable='image_view',
    #                    name='viewfinder',
    #                    remappings=[('image', '/camera/image_raw'), ])

    
    ld.add_action(cam_node)
    return ld