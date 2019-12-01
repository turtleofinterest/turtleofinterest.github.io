// PlainTextView.h : interface of the CPlainTextView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RawFileListView_H__053AD676_0AE2_11D6_8BF1_00500477589F__INCLUDED_)
#define AFX_RawFileListView_H__053AD676_0AE2_11D6_8BF1_00500477589F__INCLUDED_

#pragma once

#include "VGMTransWindow.h"
//dockable views

class RawFile;
class CBmpBtn;

#define VIEW_STYLES \
	(LVS_REPORT | LVS_SHOWSELALWAYS |/*LVS_SINGLESEL |*/ LVS_NOCOLUMNHEADER | LVS_SHOWSELALWAYS | \
   LVS_SHAREIMAGELISTS | LVS_AUTOARRANGE )
#define VIEW_EX_STYLES \
	(LVS_EX_FULLROWSELECT) //LVS_EX_AUTOSIZECOLUMNS//(WS_EX_CLIENTEDGE)

//typedef CWinTraits<WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | /*WS_HSCROLL |*/ WS_VSCROLL | WS_EX_CLIENTEDGE | TVS_HASBUTTONS> CRawFileListViewWinTraits;

class CRawFileListView : public CWindowImpl<CRawFileListView, CListViewCtrl, CWinTraitsOR<VIEW_STYLES,VIEW_EX_STYLES> >,
						 public VGMTransWindow<CRawFileListView>
					//public CEditCommands<CRawFileListView>
{
protected:
	typedef CRawFileListView thisClass;
	typedef CWindowImpl<CRawFileListView, CListViewCtrl, CWinTraitsOR<VIEW_STYLES,VIEW_EX_STYLES> > baseClass;

public:
	CRawFileListView()
	{
	}

protected:
	WTL::CImageList m_ImageList;
	//int nIconFolderIndexNormal, nIconFolderIndexSelected;
	int nGenericFileIcon;

public:
	DECLARE_WND_SUPERCLASS(NULL, CListViewCtrl::GetWndClassName())

	BOOL PreTranslateMessage(MSG* pMsg);

	BEGIN_MSG_MAP(thisClass)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		//MESSAGE_HANDLER(WM_PAINT, OnPaint)
//		MSG_WM_PAINT(OnPaint)
		MSG_WM_SIZE(OnSize)
		MSG_WM_KEYDOWN(OnKeyDown)
		MSG_WM_CONTEXTMENU(OnContextMenu)
		COMMAND_ID_HANDLER_EX(ID_SAVERAWFILE, OnSaveAsRaw)
		COMMAND_ID_HANDLER_EX(IDC_CLOSEFILE, OnCloseFile)
		//NOTIFY_CODE_HANDLER(TVN_SELCHANGED, OnTvnSelchanged) 
		//COMMAND_RANGE_HANDLER(IDC_FIRST_FILE_CLOSE_BUTTON, IDC_LAST_FILE_CLOSE_BUTTON, OnCloseButton)
		//NOTIFY_RANGE_CODE_HANDLER(IDC_FIRST_FILE_CLOSE_BUTTON, IDC_LAST_FILE_CLOSE_BUTTON, BN_CLICKED, OnCloseButtonClick)
		REFLECTED_NOTIFY_CODE_HANDLER(TVN_SELCHANGED, OnTvnSelchanged) 
		//REFLECTED_NOTIFY_CODE_HANDLER(NM_RCLICK, OnNMRClick)
		if(uMsg == WM_FORWARDMSG)
			if(PreTranslateMessage((LPMSG)lParam)) return TRUE;
		//CHAIN_MSG_MAP_ALT(CEditCommands<CPlainTextView>, 1)

		DEFAULT_REFLECTION_HANDLER()
	END_MSG_MAP()

	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	//LRESULT OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	void OnPaint ( CDCHandle /*unused*/ );
	void OnSize(UINT nType, CSize size);
	void OnKeyDown(TCHAR vkey, UINT repeats, UINT code);
	void OnLButtonDblClk(UINT nFlags, CPoint point);
	//void OnRButtonUp(UINT nFlags, CPoint point);
	//LRESULT OnCloseButton(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnTvnSelchanged(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
	LRESULT OnNMRClick(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
	LRESULT OnContextMenu(HWND hwndCtrl, CPoint ptClick );
	void OnSaveAsRaw(UINT uCode, int nID, HWND hwndCtrl);
	void OnCloseFile(UINT uCode, int nID, HWND hwndCtrl);

	void Init();
	void InitImageLists();
	void AddFile(RawFile* newFile);
	void RemoveFile(RawFile* theFile);

// Helpers

protected:
//	map<unsigned int, CTreeItem> IDtoTreeItem;
//	map<CTreeItem, CBmpBtn*> TreeItemtoBtn;
//	list<CBmpBtn*> btns;
};

extern CRawFileListView rawFileListView;

#undef VIEW_STYLES
#undef VIEW_EX_STYLES

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PlainTextView_H__053AD676_0AE2_11D6_8BF1_00500477589F__INCLUDED_)
