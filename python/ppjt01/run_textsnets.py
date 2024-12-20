
import textnets as tn

tn.params["autodownload"] = True
tn.params["seed"] = 42

corpus = tn.Corpus(tn.examples.moon_landing)

t = tn.Textnet(corpus.tokenized(), min_docs=1)


t.plot(label_nodes=True, show_clusters=True)
