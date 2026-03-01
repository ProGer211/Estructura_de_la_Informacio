Llista::Llista() : _prim(NULL), _long(0) {}
   
Llista::Llista(const vector<int> &v) : _prim(NULL), _long(v.size()) {
  node *p = NULL, *pant = NULL;
  for (int i=0; i<v.size(); i++) {
    p = new node;
    p->info = v[i];
    p->seg = NULL;
    if (pant == NULL)
      _prim = p;
    else
      pant->seg = p;
    pant = p;
  }
  if (p != NULL)
    p->seg = _prim;
}

Llista::~Llista() {
  node *p, *pelim;
  if (_prim != NULL) {
    p = _prim->seg;
    while (p != _prim) {
      pelim = p;
      p = p->seg;
      delete pelim;
    }
    delete _prim;
  }
}

nat Llista::longitud() const {
  return _long;
}

void Llista::mostra() const {
  node *p = _prim;
  cout << "[";
  if (p != NULL) {
    cout << p->info;
    p = p->seg;
    while (p != _prim) {
      cout << " " << p->info;
      p = p->seg;
    }
  }
  cout << "]" << endl;
}


int main() {
  string linea;

  while (getline(cin, linea)) {
    istringstream ss(linea);
    vector<int> v;
    int n;
    while (ss >> n) {
      v.push_back(n);
    }
    Llista l(v);
    l.duplica_capicua();
    cout << l.longitud() << " ";
    l.mostra();
  }
  return 0;
}
