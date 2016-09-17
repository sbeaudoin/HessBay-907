#pragma once

#include "PageBase.h"

/*
	Define an association between a page and its name.
*/
class PageEntry
{

	public :

		/*
			Default constructor required for the template class Navigator.
		*/
		PageEntry() 
		{};

		/*
			Initialize the instance.

			IN
			--
			name  : Name of the page for this association.
			*page : Page instance associated.
		*/
		PageEntry(PageName name, PageBase *page)
		{
			Name = name;
			Page = page;
		};

		/*
			Page instance association.
		*/
		PageBase *Page;

		/*
			Name of the page.
		*/
		PageName Name;
};
