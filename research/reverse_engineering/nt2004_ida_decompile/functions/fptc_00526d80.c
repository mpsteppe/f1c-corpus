void __stdcall fptc(UINT uTimerID, UINT uMsg, void (__thiscall *dwUser)(_DWORD, _DWORD), DWORD_PTR dw1, DWORD_PTR dw2)
{
  dwUser(0, 0);
}
