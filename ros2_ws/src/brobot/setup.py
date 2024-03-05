import os
from glob import glob
from setuptools import setup

package_name = 'brobot'

setup(
    name=package_name,
    version='0.1.9',
    # Packages to export
    packages=[package_name],
    # Files we want to install, specifically launch files
    data_files=[
        # Install marker file in the package index
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        # Include our package.xml file
        (os.path.join('share', package_name), ['package.xml']),
        # Include all launch files.
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
    ],
    # This is important as well
    install_requires=['setuptools'],
    zip_safe=True,
    author='Joseph Cristiano',
    author_email='jcristia@udel.edu',
    maintainer='Joseph Cristiano',
    maintainer_email='jcristia@udel.edu',
    keywords=['brace', 'root'],
    classifiers=[
        'Intended Audience :: Developers',
        'License :: Apache 2.0',
        'Programming Language :: Python',
        'Topic :: Agricultural Robotics',
    ],
    description='Brace root phenotyping robot',
    license='Apache 2.0',
    # Like the CMakeLists add_executable macro, you can add your python
    # scripts here.
    entry_points={
        'console_scripts': [
            'my_script = my_package.my_script:main'
        ],
    },
)
