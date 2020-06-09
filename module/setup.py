from distutils.core import setup, Extension

module1 = Extension(
	'solving_equation', # название модуля внутри Python
	 sources = ['Newtons_method.c'] # Исходные файлы модуля
)

setup(
	name = 'solving_equation',              # название модуля (my_plus.__name__)
	version = '1.1',               # версия модуля
	description = 'isVERYBIG', # описание модуля
	ext_modules= [module1]         # объекты типа Extension (мы объявили его выше)
)
