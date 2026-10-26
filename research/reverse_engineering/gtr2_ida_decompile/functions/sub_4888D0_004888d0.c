void __thiscall sub_4888D0(int this, int a2)
{
  double v3; // st7
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  HWND DlgItem; // eax
  float v9; // [esp+4h] [ebp-8h]
  float v10; // [esp+8h] [ebp-4h]

  v3 = sub_617F80(this);
  if ( v3 >= 0.33399999 )
  {
    sub_617E70(this);
    v10 = *(float *)(this + 80);
    v9 = v3;
    *(float *)(this + 80) = v10 - v9;
    if ( *(float *)(this + 80) >= -15.0 )
    {
      if ( *(float *)(this + 80) > 45.0 )
        *(_DWORD *)(this + 80) = 1110704128;
    }
    else
    {
      *(_DWORD *)(this + 80) = -1049624576;
    }
    v4 = *(_DWORD *)(this + 96);
    if ( v4 )
    {
      v5 = *(_DWORD *)(this + 88);
      if ( *(_DWORD *)(this + 520) >= v5 )
      {
        v6 = v4 - 1;
        if ( v6 )
        {
          v7 = v6 - 1;
          if ( !v7 )
          {
            *(_DWORD *)(a2 + 868) = 2;
            DlgItem = GetDlgItem(hDlg, 1185);
            EnableWindow(DlgItem, 0);
            *(_DWORD *)(this + 80) = -1050673152;
            *(_DWORD *)(this + 96) = 0;
            return;
          }
          if ( v7 == 1 )
          {
            sub_4886D0();
            *(_DWORD *)(this + 80) = -1050673152;
            *(_DWORD *)(this + 96) = 0;
            return;
          }
        }
        else
        {
          sub_47F2F0();
        }
        *(_DWORD *)(this + 80) = -1050673152;
        *(_DWORD *)(this + 96) = 0;
      }
      else if ( *(_DWORD *)(this + 524) > *(_DWORD *)(this + 92) - v5 || v10 > 0.0 && *(float *)(this + 80) <= 0.0 )
      {
        *(_DWORD *)(this + 80) = 0;
        *(_DWORD *)(this + 96) = 0;
      }
    }
  }
}
