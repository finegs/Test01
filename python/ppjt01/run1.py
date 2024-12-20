import textnets as tn
from yake import KeywordExtractor

def yake(
   corpus: tn.Corpus,
   lang: str="en",
   ngram_size: int=3,
   top: int=50,
   window: int=2
) -> tn.corpus.TidyText:
   """Use YAKE keyword extraction to break up corpus."""
   kw = KeywordExtractor(
            lan=lang,
            n=ngram_size,
            top=top,
            windowsSize=window
        )
   tt = []
   for label, doc in corpus.documents.items():
       for term, sig in kw.extract_keywords(doc):
           tt.append({"label": label, "term": term, "term_weight": 1-sig, "n": 1})
   return tn.corpus.TidyText(tt).set_index("label")
