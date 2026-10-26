int __usercall sub_4798EC@<eax>(int a1@<ecx>, char a2@<bl>, int a3@<esi>)
{
  int result; // eax
  int *v4; // esi
  int v5; // eax
  unsigned __int8 v6; // bl
  int v7; // eax
  int v8; // ebp
  const char *v9; // eax
  int v10; // edx
  CHAR v11; // [esp+Ch] [ebp-20Ch] BYREF
  __int16 v12; // [esp+Dh] [ebp-20Bh]
  char v13; // [esp+Fh] [ebp-209h]
  int v14; // [esp+10h] [ebp-208h]
  int v15; // [esp+14h] [ebp-204h]
  char v16[253]; // [esp+18h] [ebp-200h] BYREF
  __int16 v17; // [esp+115h] [ebp-103h]
  char v18; // [esp+117h] [ebp-101h]
  char Buffer[253]; // [esp+118h] [ebp-100h] BYREF
  __int16 v20; // [esp+215h] [ebp-3h]
  char v21; // [esp+217h] [ebp-1h]

  *(_BYTE *)(a3 - 61) += a2;
  v15 = a1;
  sub_49FEC0(a1);
  sub_4A0640(1);
  result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( result )
  {
    v4 = *(int **)(result + 28);
    if ( v4 )
    {
      result = (*(int (__thiscall **)(_DWORD))(*v4 + 124))(*(_DWORD *)(result + 28));
      if ( (_BYTE)result )
      {
        v12 = 0;
        Buffer[0] = byte_629120;
        v11 = byte_629120;
        v13 = 0;
        memset(&Buffer[1], 0, 0xFCu);
        v20 = 0;
        v21 = 0;
        sub_49F640(&v11);
        v5 = *v4;
        v6 = 0;
        LOBYTE(v14) = 0;
        result = (*(int (__thiscall **)(int *))(v5 + 124))(v4);
        if ( (_BYTE)result )
        {
          do
          {
            v7 = (*(int (__thiscall **)(int *, int))(*v4 + 128))(v4, v14);
            v16[0] = byte_629120;
            v8 = v7;
            memset(&v16[1], 0, 0xFCu);
            v17 = 0;
            v18 = 0;
            sub_40FF80(*(_DWORD *)(v7 + 8), v16, 255);
            v9 = *(const char **)v8;
            if ( !*(_DWORD *)v8 )
              v9 = &byte_629120;
            sub_405480(Buffer, 0xFFu, "%s%s%s%s%d", v9, &v11, v16, &v11, *(unsigned __int8 *)(v8 + 13));
            sub_49F730(Buffer, 0, 0, 0, 0);
            v10 = *v4;
            LOBYTE(v14) = ++v6;
            result = (*(int (__thiscall **)(int *))(v10 + 124))(v4);
          }
          while ( v6 < (unsigned __int8)result );
        }
      }
    }
  }
  return result;
}
