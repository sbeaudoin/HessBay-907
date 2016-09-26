#pragma once

#include "PageBase.h"
#include "PageEntry.h"

/*
	Manage the navigation between pages.

	Remarks 
	-------
	The navigation is started with an initial page name.  The navigator find this page and ask it to display itself on the screen
	and to execute its loop.  If the page requires the display of another page, it will exit the loop and indicate the new page
	who should be displayed as a return value.
	
	The template value S indicates the number of pages.  It must be the same number as the number of items in the PageName
	enumeration.
	
	The navigator uses a PageName enumeration to define all the pages who can be navigated to.  Usually, this will be defined in
	a "Global.h" file or other means you prever.  For example :
	
			enum PageName { PageA, PageB };
*/
template <int S> class Navigator
{
	public:

		/*
			Initialize the class.

			IN
			--
			pages : An array of PageEntry defining all the pages managed by the navigator and their names.
		*/
		Navigator(PageEntry* pages)
		{
			// Transfer the pages into the navigator array.
			for (int i = 0; i < S; i++)
			{
				Pages[i] = pages[i];
			}

			_currentPage = NULL;
		}

		/*
			Start the navigator with the specified page.

			IN
			--
			pageName : The name of the first page who will be displayed.
		*/
		void StartWith(PageName pageName)
		{
			// We will never exit of the navigator.  This is the equivalent of the loop method in the sketch.
			while (true)
			{
				// Get the specified page, initialize it and execute is own loop.  When the display should change for another page,
				// the displayed page will exit is loop and return the name of the new page who should be displayed.
				PageBase* nextPage = GetPage(pageName);
				_currentPage = nextPage;
				nextPage->Setup();
				pageName = nextPage->Loop();
			}
		}

		PageBase* GetCurrentPage()
		{
			return _currentPage;
		}

	private :

		/*
			The different pages managed by the navigator.
		*/
		PageEntry Pages[S];

		/*
			Find the specified page.

			IN
			--
			name   : The name of the page who should be returned.

			OUT
			---
			The specified page if it exists, else, will return null.
		*/
		PageBase* GetPage(PageName name)
		{
			PageBase *page = NULL;

			for (int i = 0; i < S; i++)
			{
				if (name == Pages[i].Name)
				{
					page = Pages[i].Page;
					_currentPage = page;
					break;
				}
			}

			return page;
		}

		/*
			Contains the current page if one is current.  If not, returns null.
		*/
		PageBase* _currentPage;
};
