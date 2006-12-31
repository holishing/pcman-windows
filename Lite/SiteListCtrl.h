// SiteListCtrl.h: interface for the CSiteListCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SITELISTCTRL_H__9867CA05_814D_4626_96A3_E645C83870A6__INCLUDED_)
#define AFX_SITELISTCTRL_H__9867CA05_814D_4626_96A3_E645C83870A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DragTreeCtrl.h"

class CListDlg;

class CSiteListCtrl : public CDragTreeCtrl  
{
public:
	HTREEITEM GetTopParent(HTREEITEM item);
	BOOL isItemDir(HTREEITEM item);
	BOOL isDefaultItem(HTREEITEM item);
	BOOL CanPaste(HTREEITEM item);
	BOOL CanCopy(HTREEITEM item);
	HTREEITEM FindChildItem(HTREEITEM parent, LPCTSTR key);
	CString GetItemFilePath(HTREEITEM item);
	void DeleteItem(HTREEITEM item, BOOL bDelFile);
	CString GetItemPath(HTREEITEM item);

	HTREEITEM bbsfavorite;
	HTREEITEM bbslist;
	HTREEITEM home;
#ifdef	_COMBO_
	HTREEITEM wwwfavorite;
#endif
	BOOL changed;
	HTREEITEM CopyTo(HTREEITEM from, HTREEITEM parent, HTREEITEM insert_after,bool prevent_dup=false);
	CSiteListCtrl();
	virtual BOOL CanDrag(HTREEITEM item);
	virtual ~CSiteListCtrl();

protected:
	virtual void MoveItem(HTREEITEM item,HTREEITEM target, bool up,bool bcopy);

	//{{AFX_MSG(CSiteListCtrl)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

inline BOOL CSiteListCtrl::CanCopy(HTREEITEM item)
{
	return FALSE;
}

inline BOOL CSiteListCtrl::CanPaste(HTREEITEM item)
{
	return item && !((GetParentItem(item)==home || item==home) && isItemDir(item));
}

inline BOOL CSiteListCtrl::isItemDir(HTREEITEM item)
{
	int image;	GetItemImage(item,image,image);
	return image==3;
}


inline BOOL CSiteListCtrl::isDefaultItem(HTREEITEM item)
{
	return (item==bbsfavorite ||
			item==bbslist ||
		#if defined(_COMBO_)
			item==wwwfavorite ||
		#endif
			item==home);	
}


#endif // !defined(AFX_SITELISTCTRL_H__9867CA05_814D_4626_96A3_E645C83870A6__INCLUDED_)