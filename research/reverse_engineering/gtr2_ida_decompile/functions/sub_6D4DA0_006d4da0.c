int __stdcall sub_6D4DA0(_DWORD *a1)
{
  int *v1; // eax
  int v2; // edx
  int v3; // eax
  int *v4; // edi
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  _DWORD *v13; // ebx
  int v14; // edx
  int v15; // ecx
  int result; // eax
  int v17; // [esp+Ch] [ebp-24h] BYREF
  int v18; // [esp+10h] [ebp-20h]
  int v19; // [esp+14h] [ebp-1Ch]
  int v20; // [esp+18h] [ebp-18h]
  int v21; // [esp+1Ch] [ebp-14h]
  int v22; // [esp+20h] [ebp-10h]
  int v23; // [esp+24h] [ebp-Ch]
  int v24; // [esp+28h] [ebp-8h]
  _DWORD *v25; // [esp+2Ch] [ebp-4h]

  v1 = (int *)a1[6];
  v2 = *v1;
  v3 = v1[1];
  v4 = (int *)(a1[93] + 12);
  v17 = v2;
  v18 = v3;
  v5 = v4[1];
  v19 = *v4;
  v6 = v4[2];
  v20 = v5;
  v7 = v4[3];
  v21 = v6;
  v8 = v4[4];
  v22 = v7;
  v9 = v4[5];
  v23 = v8;
  v24 = v9;
  v25 = a1;
  if ( sub_6D48F0((int)&v17, 127, 7) )
  {
    v10 = 0;
    v11 = 0;
  }
  else
  {
    v12 = *a1;
    *(_DWORD *)(v12 + 20) = 24;
    (*(void (__stdcall **)(_DWORD *))v12)(a1);
    v11 = v20;
    v10 = v19;
  }
  v13 = (_DWORD *)a1[6];
  *v13 = v17;
  v13[1] = v18;
  v14 = v23;
  *v4 = v10;
  v15 = v22;
  v4[1] = v11;
  v4[2] = v21;
  result = v24;
  v4[3] = v15;
  v4[4] = v14;
  v4[5] = result;
  return result;
}
