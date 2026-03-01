#include "mcj_enters.hpp"

  // Constructora per defecte. Crea un multiconjunt buit.
mcj_enters::mcj_enters()  // o mcj_enters::mcj_enters() : n(0)  { }
  {
  n = 0;
  }
  // Les tres grans: Constructora per còpia, destructora, operador d'assignació
mcj_enters::mcj_enters(const mcj_enters &cj)
  {
  n = cj.n;
	 for(unsigned int i = 0;i< n;i++)
  	{
        v[i] = cj.v[i];
  	}
  }
mcj_enters::~mcj_enters()
{
}
mcj_enters& mcj_enters::operator=(const mcj_enters &cj)
{
n = cj.n;
	 for(unsigned int i = 0;i< n;i++)
  	{
        v[i] = cj.v[i];
  	}
  return *this; //punter al parametre implicit

}

// Insereix l’enter e en el multiconjunt.
void mcj_enters::insereix(int e)
{
 int aux;
 v[n] = e;
 n = n +1;
  for(int i = n - 2;i>=0;i--)
 {
 if(v[i] > e)
 {
  aux = v[i];
  v[i] = e;
  v[i+1] = aux;
 }
 }	
 

}

// Unió, intersecció i diferència de multiconjunts. Operen modificant el multiconjunt sobre el que s’aplica
// el mètode, usant el segon multiconjunt com argument. P.e.: a.restar(b) fa que el nou valor d’a sigui
// A - B, on A i B són els valors originals dels objectes a i b.
  void mcj_enters::unir(const mcj_enters& B)
  {
   mcj_enters aux;
  int i = 0;
  int j = 0;
  while(i<n || j < B.n )
  {
  if(i == n)
  {
  aux.v[aux.n] = B.v[j];
  aux.n++;
  j++;
  }
  else if(j == B.n)
  {
  aux.v[aux.n] = v[i];
  aux.n++;
  i++;
  }
  else if(v[i]> B.v[j])
  {
  aux.v[aux.n] = B.v[j];
  aux.n++;
  j++;
  }
  else if(v[i] < B.v[j])
  {
  aux.v[aux.n] = v[i];
  aux.n++;
  i++;
  }
  	else 
  	{
  	aux.v[aux.n] = v[i];
  	aux.n++;
  	j++;
  	i++;
  	}  
  }
 
    *this = aux;
  }
  
   
  void mcj_enters::intersectar(const mcj_enters& B)
  {
   mcj_enters aux;
  int i = 0;
  int j = 0;
  while(i<n && j< B.n)
  {
  if(v[i]> B.v[j]) j++;
  else if(v[i] < B.v[j])i++;
  	else 
  	{
  	aux.v[aux.n] = v[i];
  	aux.n++;
  	j++;
  	i++;
  	}  
  }
   *this = aux;
  
  }
  
  void mcj_enters::restar(const mcj_enters& B)
  {
  mcj_enters aux;
  int i = 0;
  int j = 0;
  while(i<n && j<B.n)
  {
  if(v[i] == B.v[j])
  {
  i++;
  j++;
  
  }
  else if(v[i] > B.v[j])
  {
  j++;  
  }
  else if(v[i]< B.v[j])
  {
  aux.v[aux.n] = v[i];
  aux.n++;
  i++;  
  }
  
  } 
  while(i<n)
  {
   aux.v[aux.n] = v[i];
  aux.n++;
  i++; 
  
  } 
  
  if(B.n != 0)*this = aux;
  
  }

  // Unió, intersecció i diferència de multiconjunts. Operen creant un nou multiconjunt sense modificar el con-
  // junt sobre el que s’aplica el mètode. La suma de multiconjunts correspon a la unió, la resta a la
  // diferència i el producte a la intersecció.
  mcj_enters mcj_enters::operator+(const mcj_enters& B) const
  {
  //consultor no pot modificar el parametre implicit
  mcj_enters aux = *this; //mcj_enters aux(*this);
  
  aux.unir(B);
  return aux;
  }
  mcj_enters mcj_enters::operator*(const mcj_enters& B) const
  {
  mcj_enters aux = *this;
  aux.intersectar(B);
  return  aux;
  }
  mcj_enters mcj_enters::operator-(const mcj_enters& B) const
  {
  mcj_enters aux = *this;
  aux.restar(B);
  return  aux;
  }

  // Retorna cert si i només si e pertany al multiconjunt.
  bool mcj_enters::conte(int e) const
  {
  for(int i=0;i<n;i++)
  {
  if(v[i] == e) return true;  
  }
  return false;
  }

  // Retornen els elements màxim i mínim del multiconjunt, respectivament.
  // El seu comportament no està definit si el multiconjunt és buit.
  int mcj_enters::max() const
  {
  return v[n-1];
  }
  int mcj_enters::min() const
  {
  return v[0];
  }

  // Retorna el nombre d’elements (la cardinalitat) del multiconjunt.
  int mcj_enters::card() const
  {  
   return n;
  }

  // Operadors relacionals. == retorna cert si i només si els
  // dos multiconjunts (el paràmetre implícit i B) contenen els
  // mateixos elements; != retorna cert si i només si els
  // multiconjunts són diferents.
  bool mcj_enters::operator==(const mcj_enters& B) const
  {
  if(n != B.n) return false;
  for(int i = 0;i<n;i++)
  {
  if(v[i] != B.v[i]) return false;
  }
  return true;
  }
  bool mcj_enters::operator!=(const mcj_enters& B) const
  {
   return !(*this == B);
  }

  // Imprimeix el multiconjunt d’enters, ordenats en ordre ascendent, sobre
  // el canal de sortida os; el format és [e1 e2 ... en], és a dir, amb
  // espais entre els elements i tancant la seqüència amb corxets.
  void mcj_enters::print(ostream& os) const
  {  
  if(n == 0) os << "[]";
  else
  {
  os << "[";
  for(int i = 0;i<n - 1;i++)
  {
  os <<  v[i] << " ";
  }
  os << v[n-1] << "]";
  }
  }


