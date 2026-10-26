__int32 __userpurge sub_5C1050@<eax>(__int32 a1@<edx>, int a2@<ecx>, int a3@<edi>, __int32 a4, int a5)
{
  int v5; // ebx
  int v6; // esi
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  void (__thiscall ***v10)(_DWORD, _DWORD); // ecx
  __int32 result; // eax
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  __int32 v21; // edx
  int v22; // edi
  _DWORD *v23; // ebx
  _DWORD *v24; // eax
  _DWORD *v25; // edi
  int v26; // ecx
  int v27; // eax
  int v28; // edi
  int v29; // ecx
  int v30; // eax
  int v31; // edi
  int v32; // [esp-4h] [ebp-34h]
  int v33; // [esp+Ch] [ebp-24h]
  _UNKNOWN **v35; // [esp+14h] [ebp-1Ch] BYREF
  _DWORD *v36; // [esp+18h] [ebp-18h]
  _UNKNOWN **v37; // [esp+1Ch] [ebp-14h] BYREF
  int v38; // [esp+20h] [ebp-10h]
  int v39; // [esp+2Ch] [ebp-4h]

  v5 = a2;
  v6 = a2 + 324;
  while ( *(_DWORD *)v6 )
  {
    v7 = *(_DWORD *)(v6 + 8) + 8 * *(_DWORD *)v6 - 8;
    v8 = *(_DWORD *)(v7 + 4);
    *(_DWORD *)(v7 + 4) = 0;
    if ( v8 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(v8);
    v9 = *(_DWORD *)v6 - 1;
    v10 = (void (__thiscall ***)(_DWORD, _DWORD))(*(_DWORD *)(v6 + 8) + 8 * v9);
    *(_DWORD *)v6 = v9;
    (**v10)(v10, 0);
  }
  result = a4;
  v33 = 0;
  if ( *(int *)(a4 + 324) > 0 )
  {
    v32 = a3;
    while ( 1 )
    {
      v12 = 8 * v33;
      v13 = *(_DWORD *)(*(_DWORD *)(a4 + 332) + 8 * v33 + 4);
      if ( v13 && (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 12))(v13) )
      {
        v14 = *(_DWORD *)(v5 + 320);
        v15 = *(_DWORD *)(v14 + v12 + 4);
        v16 = v12 + v14;
        if ( v15 )
          v17 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v16 + 4) + 12))(*(_DWORD *)(v16 + 4));
        else
          v17 = 0;
        v18 = *(_DWORD *)(a4 + 332);
        v19 = *(_DWORD *)(v18 + v12 + 4);
        v20 = v12 + v18;
        if ( v19 )
          (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v20 + 4) + 12))(*(_DWORD *)(v20 + 4));
        v22 = sub_5C3FD0(v17, a5);
        v35 = &off_7296C8;
        if ( v22 )
        {
          v24 = operator new(0xCu);
          if ( v24 )
          {
            v24[2] = v22;
            v24[1] = 0;
            *v24 = off_7296E8;
            v25 = v24;
            (*(void (__thiscall **)(_DWORD *))*v24)(v24);
          }
          else
          {
            v25 = 0;
          }
          v23 = v25;
        }
        else
        {
          v23 = 0;
        }
        v36 = v23;
        v26 = *(_DWORD *)(v6 + 4);
        v27 = *(_DWORD *)v6 + 1;
        v39 = 0;
        *(_DWORD *)v6 = v27;
        if ( v26 < v27 )
        {
          v28 = v27 + 1;
          sub_4F14D0(v32);
          *(_DWORD *)(v6 + 8) = sub_5A8CF0(*(void **)(v6 + 8), 8 * v28, 2, 16, 2);
          *(_DWORD *)(v6 + 4) = v28;
        }
        sub_5BCDA0(v6, v21, *(_DWORD *)v6 - 1, (int)&v35);
        v39 = -1;
        v35 = &off_7296C8;
        v36 = 0;
        if ( v23 )
          (*(void (__thiscall **)(_DWORD *))(*v23 + 4))(v23);
      }
      else
      {
        v37 = &off_7296C8;
        v38 = 0;
        v29 = *(_DWORD *)(v6 + 4);
        v30 = *(_DWORD *)v6 + 1;
        v39 = 1;
        *(_DWORD *)v6 = v30;
        if ( v29 < v30 )
        {
          v31 = v30 + 1;
          sub_4F14D0(v32);
          *(_DWORD *)(v6 + 8) = sub_5A8CF0(*(void **)(v6 + 8), 8 * v31, 2, 16, 2);
          *(_DWORD *)(v6 + 4) = v31;
        }
        sub_5BCDA0(v6, a1, *(_DWORD *)v6 - 1, (int)&v37);
        v39 = -1;
        v37 = &off_7296C8;
        v38 = 0;
      }
      a1 = a4;
      result = ++v33;
      if ( v33 >= *(_DWORD *)(a4 + 324) )
        break;
      v5 = a2;
    }
  }
  return result;
}
