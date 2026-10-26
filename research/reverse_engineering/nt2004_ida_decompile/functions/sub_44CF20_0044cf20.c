int __stdcall sub_44CF20(_DWORD *a1, int a2, int a3, int a4, char **a5)
{
  double v5; // st7
  char v7[16]; // [esp+10h] [ebp-28h] BYREF
  double v8; // [esp+20h] [ebp-18h]
  double v9; // [esp+28h] [ebp-10h]

  sub_44A900(v7, (int)a1, a2);
  v8 = sub_44A930(v7);
  sub_44A900(v7, a2, a3);
  v9 = sub_44A930(v7);
  sub_44A900(v7, a3, (int)a1);
  v5 = sub_44A930(v7);
  if ( v8 < v9 || v8 < v5 || v8 <= 22500.0 )
  {
    if ( v9 < v8 || v9 < v5 || v9 <= 22500.0 )
    {
      if ( v5 < v8 || v5 < v9 || v5 <= 22500.0 )
      {
        return sub_44B7E0(a5, a1, a2, a3, a4, 0);
      }
      else
      {
        sub_44A8C0(v7, a3, (int)a1);
        sub_44CF20(a1, a2, v7, a4, a5);
        return sub_44CF20(v7, a2, a3, a4, a5);
      }
    }
    else
    {
      sub_44A8C0(v7, a2, a3);
      sub_44CF20(a1, a2, v7, a4, a5);
      return sub_44CF20(a1, v7, a3, a4, a5);
    }
  }
  else
  {
    sub_44A8C0(v7, (int)a1, a2);
    sub_44CF20(a1, v7, a3, a4, a5);
    return sub_44CF20(v7, a2, a3, a4, a5);
  }
}
