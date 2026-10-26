_DWORD *__usercall sub_51F480@<eax>(int a1@<ecx>, __int32 a2@<ebx>)
{
  void *v3; // edi
  void *v4; // edi
  _DWORD *result; // eax
  int v6; // eax
  int v7; // [esp+0h] [ebp-8h]

  v3 = *(void **)a1;
  if ( *(_DWORD *)a1 )
  {
    sub_51D670(*(void **)a1, a2, v7);
    j__free(v3);
    *(_DWORD *)a1 = 0;
  }
  v4 = *(void **)(a1 + 4);
  if ( v4 )
  {
    sub_51D670(*(void **)(a1 + 4), a2, v7);
    j__free(v4);
    *(_DWORD *)(a1 + 4) = 0;
  }
  result = (_DWORD *)sub_5F6160("ReflectedCarView", dword_BE10B8, 0);
  *(_DWORD *)a1 = result;
  if ( result )
  {
    *result |= 0xE0000u;
    **(_DWORD **)a1 &= 0xFFFFFF9F;
    result = (_DWORD *)sub_5F6160("ReflectedTrackView", dword_BE10B8, 0);
    *(_DWORD *)(a1 + 4) = result;
    if ( result )
    {
      *result &= 0xFFFFFF9F;
      sub_5E4DF0(sub_51C8C0, a1);
      sub_5E4E10(sub_51C8F0, a1);
      switch ( dword_B71368 )
      {
        case 0:
          sub_5E5610(1, 0);
          sub_5E5610(2, 0);
          sub_5E5610(4, 0);
          sub_5E5610(8, 0);
          sub_5E5610(16, 1);
          *(float *)(*(_DWORD *)a1 + 148) = *(float *)(*(_DWORD *)a1 + 148) * 0.1;
          break;
        case 1:
          sub_5E5610(1, 0);
          sub_5E5610(2, 0);
          sub_5E5610(4, 1);
          sub_5E5610(8, 1);
          sub_5E5610(16, 0);
          *(float *)(*(_DWORD *)a1 + 148) = *(float *)(*(_DWORD *)a1 + 148) * 0.25;
          break;
        case 2:
          sub_5E5610(1, 0);
          sub_5E5610(2, 1);
          sub_5E5610(4, 1);
          sub_5E5610(8, 1);
          sub_5E5610(16, 0);
          *(float *)(*(_DWORD *)a1 + 148) = *(float *)(*(_DWORD *)a1 + 148) * 0.5;
          break;
        case 3:
          sub_5E5610(1, 1);
          sub_5E5610(2, 1);
          sub_5E5610(4, 1);
          sub_5E5610(8, 1);
          sub_5E5610(16, 0);
          *(_DWORD *)(*(_DWORD *)a1 + 148) = *(_DWORD *)(*(_DWORD *)a1 + 148);
          break;
        default:
          break;
      }
      sub_5E4DF0(sub_51EA80, a1);
      sub_5E4E10(sub_51ED70, a1);
      sub_5E5610(1, 0);
      sub_5E5610(2, 0);
      sub_5E5610(4, 0);
      sub_5E5610(8, 0);
      sub_5E5610(16, 0);
      *(_DWORD *)(a1 + 8) = sub_51C990();
      sub_5EDA60(1, 4);
      v6 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(
             dword_FB27A4,
             "L0SCREENT0",
             0);
      sub_5EDB00(v6);
      sub_5EDB10(256, 3072);
      sub_5EDAF0(0);
      sub_5EDF20(*(_DWORD *)(a1 + 8), 0, 0.0, 0.0, 0.99998999, 0.0, 0.0, -65281);
      sub_5EDF20(*(_DWORD *)(a1 + 8), 1, 0.0, 512.0, 0.99998999, 0.0, 1.0, -65281);
      sub_5EDF20(*(_DWORD *)(a1 + 8), 2, 512.0, 512.0, 0.99998999, 1.0, 1.0, -65281);
      return (_DWORD *)sub_5EDF20(*(_DWORD *)(a1 + 8), 3, 512.0, 0.0, 0.99998999, 1.0, 0.0, -65281);
    }
  }
  return result;
}
