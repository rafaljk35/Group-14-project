from setuptools import setup
APP=['button_app.py']
OPTIONS = {
    'iconfile': 'Connect4.png',
    'argv_emulation' : True,
}
setup(
    app = APP,
    options={'py2app': OPTIONS},
    setup_requires=['py2app']
)