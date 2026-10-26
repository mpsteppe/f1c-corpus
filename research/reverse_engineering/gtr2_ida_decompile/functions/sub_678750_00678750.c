int __userpurge sub_678750@<eax>(_BYTE *a1@<eax>, unsigned int a2@<ecx>, int *a3@<esi>, int a4)
{
  int v4; // ecx
  int v5; // ebx
  int v6; // edi
  int result; // eax
  int v8; // eax

  if ( a2 >= 0xC && *a1 == 65 && a1[1] == 100 && a1[2] == 111 && a1[3] == 98 && a1[4] == 101 )
  {
    v4 = *a3;
    v5 = (unsigned __int8)a1[11];
    v6 = (unsigned __int8)a1[8];
    *(_DWORD *)(v4 + 24) = (unsigned __int8)a1[6] + ((unsigned __int8)a1[5] << 8);
    *(_DWORD *)(v4 + 28) = v6 + ((unsigned __int8)a1[7] << 8);
    *(_DWORD *)(v4 + 32) = (unsigned __int8)a1[10] + ((unsigned __int8)a1[9] << 8);
    *(_DWORD *)(v4 + 36) = v5;
    *(_DWORD *)(v4 + 20) = 76;
    result = (*(int (__stdcall **)(int *, int))(v4 + 4))(a3, 1);
    *((_BYTE *)a3 + 300) = v5;
    a3[74] = 1;
  }
  else
  {
    v8 = *a3;
    *(_DWORD *)(v8 + 20) = 78;
    *(_DWORD *)(v8 + 24) = a4 + a2;
    return (*(int (__stdcall **)(int *, int))(v8 + 4))(a3, 1);
  }
  return result;
}
