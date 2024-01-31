from setuptools import find_packages
from setuptools import setup

setup(
    name='ros2_roboclaw_driver',
    version='1.0.0',
    packages=find_packages(
        include=('ros2_roboclaw_driver', 'ros2_roboclaw_driver.*')),
)
