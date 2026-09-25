# Extractive text summarizer

A language-independent course exercise that scores sentences from a document and selects higher-scoring sentences for a short summary. The original notebook and Python script are retained; notebook outputs have been cleared for this archive.

## Run

Open `A1_ELC.ipynb` in Jupyter. The notebook expects text input supplied by the course. That input and the course PDF are not included. The standalone `a1_elc.py` file also expects a local text file, which must be supplied before it can run.

The code uses NLTK tokenization and English stop words. The notebook downloads NLTK resources when executed.

## Next improvements

Move the scoring steps into reusable functions, handle empty input and short documents, and add a small permitted sample plus tests and summary-quality examples.
