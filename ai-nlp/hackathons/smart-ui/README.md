# Smart UI hackathon project

This is an archive copy of a team submission for Smart UI at Techfest 2020–21 (Team SU-208042). Given a wireframe screenshot, the project detects and classifies UI components, extracts text and visual attributes, and writes a JSON representation; an additional stage renders that JSON as HTML.

The upstream README credits **Rishabh Arya, Shreya Laddha, and Tezan Sahu**. The account repository was a fork of [Tezan Sahu's project](https://github.com/tezansahu/smart_ui_tf20). This entry preserves the team attribution and does not present the work as a solo project.

## Project structure

- `app/uiComponentDetector/` — Image-processing and CNN-based component detection. The detector includes code adapted from [UIED](https://github.com/MulongXie/UIED); its Apache license is preserved alongside the code.
- `app/attributeExtractor/` — OCR and visual attribute extraction.
- `app/htmlGenerator/` — JSON-to-HTML rendering.
- `models/` — Training notebooks, model documentation, and a model-download script. Notebook outputs were cleared in this archive copy.
- `assets/images/` — Architecture and training figures.

## Archive limits

The original problem-statement PDF, datasets, and downloaded model weights are not included. The repository is therefore not a plug-and-play demo: running the complete pipeline requires obtaining permitted data and the referenced weights. The original project targets an older Python/TensorFlow stack; document a current environment and add tests before presenting it as a maintained application.

The root `LICENSE` retains the upstream Apache License 2.0. `app/uiComponentDetector/LICENSE-UIED` retains the license and attribution for the adapted UIED component.
