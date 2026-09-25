# Document question answering

A course exercise that answers who/when/where questions by cleaning document sentences, representing them with TF-IDF features, and ranking candidate sentences by distance to the question. The original notebook is retained with its output cleared.

## Run

Open `A2_ELC.ipynb` in Jupyter. The notebook expects a course-provided text file in its working directory. The input and course PDF are not included. The notebook uses Python, NLTK, NumPy, Gensim, and scikit-learn.

This is an early retrieval exercise, not a modern document-grounded assistant.

## Next improvements

Separate preprocessing, retrieval, and answer formatting into functions. Add a small permitted document set, evaluate retrieval with a fixed question set, and report where sentence ranking fails.
