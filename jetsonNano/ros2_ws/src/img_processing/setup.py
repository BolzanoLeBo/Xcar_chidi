from setuptools import find_packages, setup

package_name = 'img_processing'

setup(
	name=package_name,
	version='0.0.0',
	packages=[package_name],
	data_files=[
		('share/ament_index/resource_index/packages',
			['resource/' + package_name]),
		('share/' + package_name, ['package.xml']),
	],
	install_requires=['setuptools', 'img_tools'],
	zip_safe=True,
	maintainer='loic',
	maintainer_email='loic.thomas1509@gmail.com',
	description='Package description',
	license='License declaration',
	entry_points={
		'console_scripts': [
			'img_processing_node = img_processing.img_processing_node:main'
		],
	},
)
