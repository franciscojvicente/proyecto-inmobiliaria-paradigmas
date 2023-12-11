/*
 * TipoPropiedad.h
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */

#ifndef TIPOPROPIEDAD_H_
#define TIPOPROPIEDAD_H_
#include <iostream>
using namespace std;
class TipoPropiedad{
public:
	TipoPropiedad();
	virtual void Listar()=0;
	virtual string GetTipo()=0;
	virtual ~TipoPropiedad();
};




#endif /* TIPOPROPIEDAD_H_ */
