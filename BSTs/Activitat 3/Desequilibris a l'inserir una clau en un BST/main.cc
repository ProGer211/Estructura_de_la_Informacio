
template <typename Clau>
void dicc<Clau>::esborra_nodes(node* m) {
  if (m != NULL) {
    esborra_nodes(m->_esq);
    esborra_nodes(m->_dret);
    delete m;
  }
}

template <typename Clau>
dicc<Clau>::~dicc() {
  esborra_nodes(_arrel);
}


int main() {
  int n;
  dicc<int> d;
  while (cin >> n) {
    vector<int> v;
    v = d.insereix(n);
    cout << "insereix " << n << ":";
    for (nat i = 0; i < v.size(); i++) {
      cout << " " << v[i];
    }
    cout << endl;
  }
  return 0;
}
