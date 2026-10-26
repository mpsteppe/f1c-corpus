char __thiscall sub_4B8940(_BYTE *this)
{
  int v1; // esi
  double v2; // st7
  char *v3; // edi
  int *v4; // ebx
  int v5; // ebp
  char v6; // al
  float v8; // [esp+0h] [ebp-28h]
  float v9; // [esp+Ch] [ebp-1Ch]
  float v10; // [esp+14h] [ebp-14h]
  float v11; // [esp+18h] [ebp-10h]
  _DWORD *v12; // [esp+18h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-Ch] BYREF
  int v14; // [esp+20h] [ebp-8h]
  _BYTE *v15; // [esp+24h] [ebp-4h]

  v1 = (int)this;
  this[3968] = 1;
  v15 = this;
  v10 = 0.0;
  v11 = 0.75 * 1.5;
  SafeDivisionWithZeroGuard((int)&flt_5EA4E8, v11);
  if ( v11 > 0.0 )
  {
    do
    {
      v13 = 1;
      StateTriggerCheck(&v13);
      v2 = dbl_8AFE90 + v10;
      v10 = v2;
    }
    while ( v2 < v11 );
  }
  *(_BYTE *)(v1 + 3968) = 1;
  v9 = dbl_8AFEA0;
  v13 = 1;
  AngleClampWrap(v1, v9);
  StateTriggerCheck(&v13);
  *(_BYTE *)(v1 + 3969) = 0;
  v14 = dword_5C329C;
  if ( dword_5C329C > 0 )
  {
    v12 = (_DWORD *)(v1 + 1844);
    v3 = (char *)(v1 + 2364);
    v4 = dword_7C54F0;
    do
    {
      v5 = *v4;
      SessionStateTransition(*v12, 0);
      UIElementIterateUpdate(v5 + 1776);
      v6 = *(v3 - 104);
      if ( *(_BYTE *)(v5 + 4189) != v6 )
      {
        *(_BYTE *)(v5 + 4189) = v6;
        AudioSoundEffectController(*(_DWORD *)(v5 + 4180));
      }
      v8 = dbl_8AFEA0;
      MultiObjectRemove(v8);
      SetDriverVisibility(*v3);
      ++v4;
      ++v12;
      ++v3;
    }
    while ( (int)&v3[-2364 - v1] < v14 );
    v1 = (int)v15;
  }
  SessionStructureCleanup(dword_5EA560);
  GuardedVirtualCall(1065353216);
  sub_566DB0(*(_DWORD *)(v1 + 3904));
  *(_DWORD *)(v1 + 3904) = -1;
  return 1;
}
