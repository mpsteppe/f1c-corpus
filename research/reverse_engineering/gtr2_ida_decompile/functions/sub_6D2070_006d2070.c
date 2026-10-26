int __usercall sub_6D2070@<eax>(int a1@<eax>)
{
  _DWORD *v2; // edi
  int v3; // eax
  int (__stdcall **v4)(int, int, int); // ecx
  int v5; // eax
  int (__stdcall **v6)(int, int, int); // edx
  int v7; // eax
  int *v8; // ecx
  int v9; // eax
  int v10; // ebx
  int v11; // esi
  int v12; // edx
  int result; // eax
  int v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  int v17; // [esp+14h] [ebp-8h]
  int v18; // [esp+18h] [ebp-4h]

  v2 = *(_DWORD **)(a1 + 460);
  v3 = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  v4 = *(int (__stdcall ***)(int, int, int))(a1 + 4);
  v2[2] = v3;
  v5 = (*v4)(a1, 1, 1024);
  v6 = *(int (__stdcall ***)(int, int, int))(a1 + 4);
  v2[3] = v5;
  v2[4] = (*v6)(a1, 1, 1024);
  v7 = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  v8 = (int *)v2[3];
  v2[5] = v7;
  v16 = v7;
  v14 = v2[4] - (_DWORD)v8;
  v9 = v2[2] - (_DWORD)v8;
  v18 = 5990656;
  v10 = -14831872;
  v11 = -11728000;
  v12 = 2919680;
  v15 = v9;
  v17 = v16 - (_DWORD)v8;
  while ( 1 )
  {
    *(int *)((char *)v8 + v9) = v11 >> 16;
    *v8 = v10 >> 16;
    *(int *)((char *)v8 + v14) = v18;
    *(int *)((char *)v8 + v17) = v12;
    result = v18 - 46802;
    v12 -= 22554;
    v11 += 91881;
    v10 += 116130;
    ++v8;
    v18 -= 46802;
    if ( v12 < -2831590 )
      break;
    v9 = v15;
  }
  return result;
}
