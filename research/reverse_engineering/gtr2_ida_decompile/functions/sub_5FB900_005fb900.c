int __userpurge sub_5FB900@<eax>(_DWORD *a1@<ecx>, _DWORD *a2@<edi>, int a3@<esi>, int a4, int a5)
{
  int v5; // ebp
  int result; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // esi
  char *v9; // eax
  int v10; // edi
  char v11; // cl
  _DWORD *v12; // eax
  int v13; // esi

  (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_FB27A4 + 112))(dword_FB27A4, a5);
  v5 = 0;
  result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 188))(dword_FB27A4);
  if ( result > 0 )
  {
    do
    {
      v7 = operator new(0x130u);
      v8 = v7;
      if ( v7 )
      {
        sub_5D9010(v7);
        *v8 = 0;
        v8[72] = 0;
        v8[73] = 0;
        v8[74] = 0;
        v8[75] = 0;
        v8[67] = v5;
        v8[68] = v5;
      }
      else
      {
        v8 = 0;
      }
      *v8 = 0;
      sub_51F420(v8 + 72);
      v8[65] = 0;
      v8[66] = 0;
      *((_BYTE *)v8 + 4) = 0;
      v8[69] = 0;
      v8[70] = 0;
      v8[71] = 0;
      v9 = (char *)((*(int (__thiscall **)(int, int, _DWORD *, int))(*(_DWORD *)dword_FB27A4 + 196))(
                      dword_FB27A4,
                      v5,
                      a2,
                      a3)
                  + 32);
      v10 = (char *)(v8 + 1) - v9;
      do
      {
        v11 = *v9;
        v9[v10] = *v9;
        ++v9;
      }
      while ( v11 );
      v8[67] = v5;
      v8[68] = 0;
      v8[69] = 0;
      a3 = 0;
      a2 = v8;
      (*(void (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 116))(dword_FB27A4);
      v12 = operator new(0xCu);
      if ( v12 )
      {
        *v12 = v8;
        v12[1] = 0;
        *((_BYTE *)v12 + 8) = 1;
      }
      else
      {
        v12 = 0;
      }
      if ( *a1 )
      {
        *(_DWORD *)(a1[1] + 4) = v12;
      }
      else
      {
        *a1 = v12;
        a1[2] = v12;
      }
      v13 = a1[3] + 1;
      a1[1] = v12;
      a1[3] = v13;
      ++v5;
      result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 188))(dword_FB27A4);
    }
    while ( v5 < result );
  }
  return result;
}
