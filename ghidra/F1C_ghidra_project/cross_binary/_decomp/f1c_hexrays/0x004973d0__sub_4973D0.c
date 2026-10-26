// f1c  0x004973d0  size=197
void __thiscall sub_4973D0(int this)
{
  _DWORD *v2; // eax
  char *v3; // edx
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // ebx
  int v8; // ebp
  int v9; // edi
  int v10; // esi
  int v11; // eax
  int **v12; // eax
  int v13; // [esp+8h] [ebp-4h]

  if ( *(float *)(this + 196) > 0.2 && *(_DWORD *)(this + 5480) )
  {
    v2 = sub_495980((_DWORD *)this);
    if ( !v2 )
      goto LABEL_8;
    v3 = *(char **)(this + 5464);
    if ( !v3 )
      v3 = byte_5EA438;
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, char *))(*v2 + 128))(v2, v3) == 1 )
    {
      v4 = *(_DWORD *)(this + 5480);
      v13 = v4;
    }
    else
    {
LABEL_8:
      v4 = sub_497AD0(aNodropicon0000, 0);
      v13 = v4;
    }
    if ( v4 )
    {
      v5 = *(_DWORD *)(v4 + 12);
      v6 = *(_DWORD *)(this + 92);
      v7 = *(_DWORD *)(this + 96);
      v8 = *(_DWORD *)(v5 + 32);
      v9 = *(_DWORD *)(v5 + 28);
      v10 = v6 - v9;
      v11 = sub_495150();
      sub_494A30(*(_DWORD *)(v13 + 12), 0, 0, v11, v10, v7, v9, v8, 0, 0);
      v12 = (int **)sub_490920();
      sub_4918D0(v12, v10, v7, v9, v8);
    }
  }
}
