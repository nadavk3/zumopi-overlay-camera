from setuptools import setup

package_name = 'zumo_camera_streamer'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='zumo',
    maintainer_email='zumo@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "pub_node = zumo_camera_streamer.camera_talker_node:main",
            "sub_node = zumo_camera_streamer.camera_listener_node:main",
            "loc_node = zumo_camera_streamer.location_finder_node:main",
            "cam_debug_node = zumo_camera_streamer.debug_camera_listener_node:main"
        ],
    },
)
