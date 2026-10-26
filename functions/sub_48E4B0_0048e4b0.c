int __thiscall sub_48E4B0(void *this, int a2, int a3, int a4, int a5)
{
  char *v6; // eax
  char *v7; // ecx
  _DWORD *v9; // eax
  int **v10; // eax
  int v11; // [esp-10h] [ebp-14h]
  int v12; // [esp-Ch] [ebp-10h]
  int v13; // [esp-Ch] [ebp-10h]
  int v14; // [esp-8h] [ebp-Ch]
  int v15; // [esp-8h] [ebp-Ch]
  int v16; // [esp-4h] [ebp-8h]

  v6 = (char *)*((_DWORD *)this + 44);
  if ( !v6 )
    v6 = byte_5EA438;
  v7 = (char *)*((_DWORD *)this + 63);
  if ( !v7 )
    v7 = byte_5EA438;
  if ( sub_588410(v7, v6) )
  {
    (*(void (__thiscall **)(void *))(*(_DWORD *)this + 160))(this);
    return 0;
  }
  else
  {
    if ( *((_DWORD *)this + 57) && *((_BYTE *)this + 248) )
    {
      v14 = *((_DWORD *)this + 59);
      v12 = *((_DWORD *)this + 58);
      v9 = (_DWORD *)GlobalAccessor_5150();
      if ( BinkVideoFrameRender(*((_DWORD **)this + 57), v9, v12, v14, 32) )
      {
        v16 = *((_DWORD *)this + 61);
        v15 = *((_DWORD *)this + 60);
        v13 = *((_DWORD *)this + 59);
        v11 = *((_DWORD *)this + 58);
        *((_BYTE *)this + 248) = 0;
        v10 = (int **)Accessor();
        RenderSurfaceFillCopy(v10, v11, v13, v15, v16);
      }
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 44))(this, 1);
      (*(void (__thiscall **)(void *, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this + 16))(
        this,
        *((_DWORD *)this + 59),
        *((_DWORD *)this + 61),
        *((_DWORD *)this + 58),
        *((_DWORD *)this + 60));
    }
    return 0;
  }
}
