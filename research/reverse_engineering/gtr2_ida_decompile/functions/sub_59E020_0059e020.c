char __thiscall sub_59E020(char *this, int a2)
{
  int v2; // esi
  int v4; // eax
  int v5; // eax
  int v7; // esi
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  int *v11; // eax
  bool v12; // zf
  int v13; // edi
  int v14; // eax
  int *v15; // eax
  int v16; // edi
  int *v17; // ebp
  int v18; // ecx
  int v19; // edx
  _DWORD **v20; // eax
  int v21; // ecx
  _DWORD *v22; // esi
  int v23; // eax
  _DWORD **v24; // eax
  int v25; // [esp+Ch] [ebp-20h] BYREF
  int v26; // [esp+10h] [ebp-1Ch]
  int v27; // [esp+14h] [ebp-18h]
  int v28; // [esp+18h] [ebp-14h]
  int v29; // [esp+1Ch] [ebp-10h] BYREF
  int v30; // [esp+20h] [ebp-Ch]
  int v31; // [esp+24h] [ebp-8h]
  int v32; // [esp+28h] [ebp-4h]

  v2 = a2;
  if ( sub_5A6C10(a2) )
    return 1;
  v4 = sub_5A6C20(v2) - 5;
  if ( !v4 )
  {
    (*(void (__thiscall **)(char *))(*(_DWORD *)this + 116))(this);
    return 1;
  }
  v5 = v4 - 1;
  if ( v5 )
  {
    if ( v5 == 5 )
    {
      v7 = sub_59C4C0();
      htonl(0);
      htons(0);
      v8 = *((_DWORD *)this + 681);
      v29 = *((_DWORD *)this + 680);
      v9 = *((_DWORD *)this + 682);
      v30 = v8;
      v10 = *((_DWORD *)this + 683);
      v11 = *(int **)v7;
      v12 = *(_DWORD *)v7 == 0;
      v31 = v9;
      v32 = v10;
      *(_DWORD *)(v7 + 8) = v11;
      if ( !v12 )
      {
        v13 = *v11;
        if ( *v11 )
        {
          while ( !sub_59C230(v13, &v29) )
          {
            v14 = *(_DWORD *)(v7 + 8);
            if ( v14 )
            {
              v15 = *(int **)(v14 + 4);
              *(_DWORD *)(v7 + 8) = v15;
              if ( v15 )
              {
                v13 = *v15;
                if ( *v15 )
                  continue;
              }
            }
            goto LABEL_14;
          }
          *(float *)(v13 + 48) = sub_5A3EA0(this);
        }
      }
LABEL_14:
      if ( *((_DWORD *)this + 694) )
        ReleaseMutex(*((HANDLE *)this + 694));
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    htonl(0);
    htons(0);
    v25 = 0;
    v26 = 0;
    v27 = 0;
    v28 = 0;
    a2 = 0;
    sub_5A6980(&v25, 16, &a2);
    if ( a2 == 16 )
    {
      v16 = sub_59C4C0();
      sub_59CFD0();
      v17 = (int *)(this + 2720);
      v18 = *v17;
      v19 = v17[1];
      v31 = v17[2];
      v20 = *(_DWORD ***)v16;
      v12 = *(_DWORD *)v16 == 0;
      v29 = v18;
      v21 = v17[3];
      v30 = v19;
      v32 = v21;
      *(_DWORD *)(v16 + 8) = v20;
      if ( !v12 )
      {
        v22 = *v20;
        if ( *v20 )
        {
          while ( !sub_59C230((int)v22, &v29) )
          {
            v23 = *(_DWORD *)(v16 + 8);
            if ( v23 )
            {
              v24 = *(_DWORD ***)(v23 + 4);
              *(_DWORD *)(v16 + 8) = v24;
              if ( v24 )
              {
                v22 = *v24;
                if ( *v24 )
                  continue;
              }
            }
            goto LABEL_24;
          }
          *v22 = v25;
          v22[1] = v26;
          v22[2] = v27;
          v22[3] = v28;
        }
      }
LABEL_24:
      sub_59C4F0();
      return 1;
    }
    else
    {
      return 1;
    }
  }
}
