// src\HyperEditHash.cpp : 实现文件
//
#include "stdafx.h"

#include "HyperEditHash.h"


// CHyperEditHash

IMPLEMENT_DYNAMIC(CHyperEditHash, CHyperEdit)

CHyperEditHash::CHyperEditHash()
{

}

CHyperEditHash::~CHyperEditHash()
{
}


BEGIN_MESSAGE_MAP(CHyperEditHash, CHyperEdit)
END_MESSAGE_MAP()



// CHyperEditHash 消息处理程序
BOOL CHyperEditHash::PreTranslateMessage(MSG* pMsg)
{  
    // 编辑框快捷键操作  
    if(WM_KEYDOWN == pMsg->message)   
    {  
        if(::GetFocus() == m_hWnd && (GetKeyState( VK_CONTROL) & 0xFF00 ) == 0xFF00)   
        {  
            // 全选  
            if( pMsg->wParam == 'A' || pMsg->wParam == 'a')  
            {  
                this->SetSel(0, -1);  
                return true;  
            }  
      
            // 拷贝  
            if( pMsg->wParam == 'C' || pMsg->wParam == 'c')  
            {  
                this->Copy();  
                return true;  
            }  
   
            // 剪切  
            if( pMsg->wParam == 'X' || pMsg->wParam == 'x')  
            {  
                this->Cut();  
                return true;  
            }  
      
            // 粘贴  
            if( pMsg->wParam == 'V' || pMsg->wParam == 'v')  
            {  
                this->Paste();  
                return true;  
            }  
      
            // 粘贴  
            if( pMsg->wParam == 'Z' || pMsg->wParam == 'z')  
            {  
                this->Undo();  
                return true;  
             }  
      
        }  
    }  
      
    return CHyperEdit::PreTranslateMessage(pMsg);  
 }  

