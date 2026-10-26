void __stdcall sub_5F6260(int a1)
{
  int v1; // eax
  int v2; // eax
  char *v3; // eax
  char **v4; // eax
  int v5; // edi
  int v6; // [esp-18h] [ebp-20h]

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 104);
    if ( v1 )
    {
      v2 = *(_DWORD *)(v1 + 392);
      if ( v2 )
      {
        if ( *(_DWORD *)(v2 + 620) )
        {
          v3 = (char *)sub_5E82A0(*(_DWORD **)(a1 + 4), 99);
          v4 = sub_5F5FB0(v3);
          if ( v4
            && (v5 = (*(int (__thiscall **)(int, char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(dword_FB27A4, *v4, 0)) != 0 )
          {
            sub_5E9620(5, 2);
            v6 = *(_DWORD *)(a1 + 4);
            *(_DWORD *)(a1 + 88) = v5;
            sub_5F7C20(v6, 3);
            *(_DWORD *)(*(_DWORD *)(a1 + 4) + 252) = 3;
            **(_DWORD **)(a1 + 104) |= 0x400u;
          }
          else
          {
            **(_DWORD **)(a1 + 104) |= (unsigned int)&dword_1000000;
          }
        }
      }
    }
  }
}
