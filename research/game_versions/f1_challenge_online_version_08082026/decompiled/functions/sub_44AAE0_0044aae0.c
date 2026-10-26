int __stdcall sub_44AAE0(_DWORD *a1, int a2, int a3, int a4, char **a5)
{
  double v5; // st7
  char v7[16]; // [esp+10h] [ebp-28h] BYREF
  double v8; // [esp+20h] [ebp-18h]
  double v9; // [esp+28h] [ebp-10h]

  sub_4484C0(v7, (int)a1, a2);
  v8 = sub_4484F0(v7);
  sub_4484C0(v7, a2, a3);
  v9 = sub_4484F0(v7);
  sub_4484C0(v7, a3, (int)a1);
  v5 = sub_4484F0(v7);
  if ( v8 < v9 || v8 < v5 || v8 <= 22500.0 )
  {
    if ( v9 < v8 || v9 < v5 || v9 <= 22500.0 )
    {
      if ( v5 < v8 || v5 < v9 || v5 <= 22500.0 )
      {
        return sub_4493A0(a5, a1, a2, a3, a4, 0);
      }
      else
      {
        sub_448480(v7, a3, (int)a1);
        sub_44AAE0(a1, a2, v7, a4, a5);
        return sub_44AAE0(v7, a2, a3, a4, a5);
      }
    }
    else
    {
      sub_448480(v7, a2, a3);
      sub_44AAE0(a1, a2, v7, a4, a5);
      return sub_44AAE0(a1, v7, a3, a4, a5);
    }
  }
  else
  {
    sub_448480(v7, (int)a1, a2);
    sub_44AAE0(a1, v7, a3, a4, a5);
    return sub_44AAE0(v7, a2, a3, a4, a5);
  }
}
