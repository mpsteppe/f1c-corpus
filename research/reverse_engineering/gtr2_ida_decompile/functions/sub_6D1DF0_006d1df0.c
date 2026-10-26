__m64 *__stdcall sub_6D1DF0(int *a1, int a2, unsigned __int8 **a3, int *a4)
{
  int v4; // edx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // eax

  v4 = a2;
  if ( *(_DWORD *)(a2 + 40) <= 0x10u )
    return (__m64 *)sub_6D1670(a4, (int)a1, v4, a3);
  v5 = a1[79];
  v6 = 0;
  if ( v5 > 0 )
  {
    while ( ((int)a3[v6] & 7) == 0 )
    {
      if ( ++v6 >= v5 )
        goto LABEL_7;
    }
    v7 = *a1;
    *(_DWORD *)(v7 + 20) = 2;
    (*(void (__stdcall **)(int *, int))(v7 + 4))(a1, -1);
    v4 = a2;
  }
LABEL_7:
  if ( v6 == a1[79] && ((v8 = a1[18], v8 == 5) || v8 == 6) )
    return sub_6D17A0(a4, v4, (int)a1, (int)a3);
  else
    return (__m64 *)sub_6D1670(a4, (int)a1, v4, a3);
}
