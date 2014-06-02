/*
 * ColorModel.h
 *
 *  Created on: 23.05.2014
 *      Author: ddreval
 */

#ifndef COLORMODEL_H_
#define COLORMODEL_H_

#include <FBase.h>
#include <FApp.h>

#include <FUi.h>

using Osp::Graphics::Color;
using Osp::Graphics::Bitmap;

class ColorModel {

	public:
		ColorModel();
		ColorModel(int id);
		virtual ~ColorModel();

	public:
		Color formBkgColor;
		Color controlNormalBkgColor;
		Color controlPressedBkgColor;
		Color textColor;
		Color cellColor;
		Bitmap normalBackgroundBitmap;
		Bitmap pressedBackgroundBitmap;


};



#endif /* COLORMODEL_H_ */
