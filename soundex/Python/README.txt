PROBLEM SPECIFICATION:
Using the definition on Wikipedia, there exists two versions of American Soundex with differences:
ALGORITHM 0:
1. Retain the first letter of the name and drop all other occurrences of a, e, i, o, u, y, h, w.

2. Replace consonants with digits as follows (after the first letter):
      b, f, p, v → 1
      c, g, j, k, q, s, x, z → 2
      d, t → 3
      l → 4
      m, n → 5
      r → 6
3. If two or more letters with the same number are adjacent in the original name (before step 1), only retain the first letter; 
also two letters with the same number separated by 'h' or 'w' are coded as a single number, whereas such letters separated by a vowel are coded twice. 
This rule also applies to the first letter.

4. If you have too few letters in your word that you can't assign three numbers, append with zeros until there are three numbers. 
If you have more than 3 letters, just retain the first 3 numbers.


Using this algorithm, both "Robert" and "Rupert" return the same string "R163" while "Rubin" yields "R150". 
"Ashcraft" and "Ashcroft" both yield "A261" and not "A226" 
(the chars 's' and 'c' in the name would receive a single number of 2 and not 22 since an 'h' lies in between them). 
"Tymczak" yields "T522" not "T520" (the chars 'z' and 'k' in the name are coded as 2 twice since a vowel lies in between them). 
"Pfister" yields "P236" not "P123" (the first two letters have the same number and are coded once as 'P'), and "Honeyman" yields "H555".


ALGORITHM 1:
The following algorithm is followed by most SQL languages (excluding PostgreSQL[example needed]):

1. Save the first letter. Remove all occurrences of a, e, i, o, u, y, h, w.
2. Replace all consonants (include the first letter) with digits as in [2.] above.
3. Replace all adjacent same digits with one digit.
4. If the saved letter's digit is the same as the resulting first digit, remove the digit (keep the letter).
5. Append 3 zeros if result contains less than 3 digits. Remove all except first letter and 3 digits after it (This step same as [4.] in explanation above).

The two algorithms above do not return the same results in all cases primarily because of the difference between when the vowels are removed. 
The first algorithm is used by most programming languages and the second is used by SQL. 
As examples, both "Robert" and "Rupert" yield "R163", while "Tymczak" yields "T520" and "Honeyman" yields "H500". 


TO RUN THE PROGRAM:
  $ python3 soundex.py input1 input2 ... inputn mode
  mode is a mandatory input that can either be 0 or 1, indicating which algorithm to run.

DEPENDENCIES:
the built-in package `sys`;
Python 3.6.1 :: Anaconda custom (64-bit);

Installed pip packages:
absl-py (0.1.7)
alabaster (0.7.10)
anaconda-client (1.6.3)
anaconda-navigator (1.6.2)
anaconda-project (0.6.0)
appnope (0.1.0)
appscript (1.0.1)
asn1crypto (0.22.0)
astroid (1.4.9)
astropy (1.3.2)
Babel (2.4.0)
backports.shutil-get-terminal-size (1.0.0)
beautifulsoup4 (4.6.0)
bintrees (2.0.7)
bitarray (0.8.1)
blaze (0.10.1)
bleach (1.5.0)
bokeh (0.12.5)
boto (2.46.1)
Bottleneck (1.2.1)
cffi (1.10.0)
chardet (3.0.3)
click (6.7)
cloudpickle (0.2.2)
clyent (1.2.2)
colorama (0.3.9)
conda (4.4.10)
contextlib2 (0.5.5)
cryptography (1.8.1)
cycler (0.10.0)
Cython (0.25.2)
cytoolz (0.8.2)
dask (0.14.3)
datashape (0.5.4)
decorator (4.0.11)
distributed (1.16.3)
docutils (0.13.1)
entrypoints (0.2.2)
et-xmlfile (1.0.1)
facebook-wda (0.2.2.dev1)
fastcache (1.0.2)
Flask (0.12.2)
Flask-Cors (3.0.2)
gdax (1.0.6)
gevent (1.2.1)
greenlet (0.4.12)
h5py (2.7.0)
HeapDict (1.0.0)
html5lib (0.9999999)
idna (2.5)
imagesize (0.7.1)
ipykernel (4.6.1)
ipython (5.3.0)
ipython-genutils (0.2.0)
ipywidgets (6.0.0)
isort (4.2.5)
itsdangerous (0.24)
jdcal (1.3)
jedi (0.10.2)
Jinja2 (2.9.6)
jsonschema (2.6.0)
jupyter (1.0.0)
jupyter-client (5.0.1)
jupyter-console (5.1.0)
jupyter-core (4.3.0)
lazy-object-proxy (1.2.2)
llvmlite (0.18.0)
locket (0.2.0)
lxml (3.7.3)
Markdown (2.6.10)
MarkupSafe (0.23)
matplotlib (2.0.2)
mistune (0.7.4)
mpmath (0.19)
msgpack-python (0.4.8)
multipledispatch (0.4.9)
mysql-connector (2.1.6)
mysql-connector-python-rf (2.2.2)
navigator-updater (0.1.0)
nbconvert (5.1.1)
nbformat (4.3.0)
networkx (1.11)
nltk (3.2.3)
nose (1.3.7)
notebook (5.0.0)
numba (0.33.0)
numexpr (2.6.4)
numpy (1.12.1)
numpydoc (0.6.0)
odo (0.5.0)
olefile (0.44)
opencv-python (3.4.0.12)
openpyxl (2.4.7)
packaging (16.8)
pandas (0.20.1)
pandocfilters (1.4.1)
partd (0.3.8)
pathlib2 (2.2.1)
patsy (0.4.1)
pep8 (1.7.0)
pexpect (4.2.1)
pickleshare (0.7.4)
Pillow (4.1.1)
pip (9.0.1)
ply (3.10)
prompt-toolkit (1.0.14)
protobuf (3.5.1)
psutil (5.2.2)
ptyprocess (0.5.1)
py (1.4.33)
pycosat (0.6.3)
pycparser (2.17)
pycrypto (2.6.1)
pycurl (7.43.0)
pyflakes (1.5.0)
Pygments (2.2.0)
pylint (1.6.4)
pymongo (3.6.0)
PyMySQL (0.7.11)
pyodbc (4.0.16)
pyOpenSSL (17.0.0)
pyparsing (2.1.4)
pytest (3.0.7)
python-dateutil (2.6.0)
pytz (2017.2)
PyWavelets (0.5.2)
PyYAML (3.12)
pyzmq (16.0.2)
QtAwesome (0.4.4)
qtconsole (4.3.0)
QtPy (1.2.1)
requests (2.13.0)
rope-py3k (0.9.4.post1)
scikit-image (0.13.0)
scikit-learn (0.19.1)
scipy (1.0.0)
seaborn (0.7.1)
setuptools (27.2.0)
simplegeneric (0.8.1)
singledispatch (3.4.0.3)
six (1.10.0)
snowballstemmer (1.2.1)
sortedcollections (0.5.3)
sortedcontainers (1.5.7)
Sphinx (1.5.6)
spyder (3.1.4)
SQLAlchemy (1.1.9)
statsmodels (0.8.0)
sympy (1.0)
tables (3.3.0)
tblib (1.3.2)
tensorflow (1.4.0)
tensorflow-tensorboard (0.1.8)
terminado (0.6)
testpath (0.3)
toolz (0.8.2)
torch (0.3.1.post2)
torchvision (0.2.0)
tornado (4.5.1)
traitlets (4.3.2)
unicodecsv (0.14.1)
wcwidth (0.1.7)
websocket-client (0.40.0)
Werkzeug (0.12.2)
wheel (0.29.0)
widgetsnbextension (2.0.0)
wrapt (1.10.10)
xlrd (1.0.0)
XlsxWriter (0.9.6)
xlwings (0.10.4)
xlwt (1.2.0)
zict (0.1.2)

I am using pip version 9.0.1

