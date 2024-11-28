/****************************************************************************************************
*  section == leader key sequences
****************************************************************************************************/

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {

    if (leader_sequence_one_key(QK_LEAD)) {             // LEAD LEAD = CAPS  (a bit slow to activate)
      tap_code(KC_CAPS);
    
    } else if (leader_sequence_one_key(KC_QUOT)) {             // with the following seq, helps check active layout.
      SEND_STRING("Dvorak");
    
    } else if (leader_sequence_one_key(KC_Q)) {                // with the preceding, helps check active layout.
      SEND_STRING("Querty");
    
    } else if (leader_sequence_one_key(KC_D)) {                // year and month
      SEND_STRING("2023-10-");
    
    } else if (leader_sequence_one_key(KC_R)) {                // Regards, \nPeter
      SEND_STRING("Regards,\nPeter");
    
    } else if (leader_sequence_one_key(KC_LBRC)) {             // mostly intended to indent markdown bullets
      tap_code16(G(KC_LEFT));
      tap_code(KC_DEL);
      tap_code16(G(KC_RIGHT));
    
    } else if (leader_sequence_one_key(KC_T)) {                // Insert markdown for "todo" 
      SEND_STRING("- [ ] ");
   
    /* } else if (leader_sequence_one_key(KC_J)) {                // Invoke Alfred with jj keyword
    *  tap_code16(G(KC_SPC));
    *  SEND_STRING(SS_DELAY(200));
    *  SEND_STRING("jj ");
    */  
    
    } else if (leader_sequence_one_key(KC_J)) {                // Invoke Alfred with jj keyword
      SEND_STRING("JIRA:");
    
    } else if (leader_sequence_two_keys(KC_J, KC_P)) {                // Invoke Alfred with jj keyword
      SEND_STRING("JIRA:PPS-");
    
    } else if (leader_sequence_two_keys(KC_J, KC_M)) {                // Invoke Alfred with jj keyword
      SEND_STRING("JIRA:PPS-");
    
    } else if (leader_sequence_two_keys(KC_J, KC_G)) {                // Invoke Alfred with jj keyword
      SEND_STRING("JIRA:GPE-");
    
    } else if (leader_sequence_one_key(KC_L)) {                // Invoke Alfred with link keyword
      tap_code16(G(KC_SPC));
      SEND_STRING(SS_DELAY(200));
      SEND_STRING("link ");
    
    } else if (leader_sequence_one_key(KC_S)) {                // Execute Slack forward to me and back
      tap_code16(KC_F);
      SEND_STRING(SS_DELAY(600));
      SEND_STRING("Vassilatos");
      SEND_STRING(SS_DELAY(300));
      tap_code16(KC_ENT);
      SEND_STRING(SS_DELAY(300));
      register_code(KC_LSFT);
      tap_code16(KC_TAB);
      tap_code16(KC_TAB);
      unregister_code(KC_LSFT);
      tap_code16(KC_ENT);
      SEND_STRING(SS_DELAY(600));
      tap_code16(G(KC_LBRC));

    } else if (leader_sequence_one_key(KC_H)) {                // Invoke Hook with CTRL-t
      tap_code16(C(KC_H));
      SEND_STRING(SS_DELAY(300));
      tap_code16(C(KC_T));
    
    } else if (leader_sequence_one_key(KC_O)) {                // Invoke Hook with LGUI-N, currently mapped to Omnifocus
        tap_code16(C(KC_H));
        SEND_STRING(SS_DELAY(400));
        tap_code16(G(KC_N));
        SEND_STRING(SS_DELAY(400));
        tap_code16(G(KC_TAB));

    } else if (leader_sequence_two_keys(KC_O, KC_E)) {         // Invoke Hook for Omnifocus from DT3

        register_code(KC_LSFT);
        register_code(KC_LGUI);
        tap_code16(KC_LEFT);
        tap_code16(KC_RIGHT);
        unregister_code(KC_LSFT);
        unregister_code(KC_LGUI);

        tap_code16(C(KC_H));
        SEND_STRING(SS_DELAY(200));

        // -----> Select the ctl-q option (copy selection and link)
        tap_code16(C(KC_T));
        SEND_STRING(SS_DELAY(100));
        tap_code16(C(KC_Q));
        SEND_STRING(SS_DELAY(100));

        // -----> Invoke Hook 
        //tap_code16(C(KC_H));
        //SEND_STRING(SS_DELAY(100));

        // -----> Select the command option for omnifocus
        tap_code16(G(KC_N));
        SEND_STRING(SS_DELAY(500));

        // -----> tab into the new item, left arrow, space, paste
        tap_code(KC_TAB);
        SEND_STRING(SS_DELAY(400));
        tap_code(KC_TAB);
        SEND_STRING(SS_DELAY(400));
        tap_code16(G(KC_V));
        SEND_STRING(SS_DELAY(500));

        // -----> Invoke Hook 
        tap_code16(C(KC_H));
        SEND_STRING(SS_DELAY(200));

        // -----> Copy Link
        tap_code16(G(KC_C));
        SEND_STRING(SS_DELAY(100));

        // -----> return to previous app
        tap_code16(G(KC_TAB));
        SEND_STRING(SS_DELAY(400));

        // -----> insert todo and OF link markup
        tap_code(KC_RIGHT);
        SEND_STRING("](");
        SEND_STRING(SS_DELAY(200));
        tap_code16(G(KC_V));
        SEND_STRING(")");
        tap_code16(G(KC_LEFT));
        SEND_STRING("- [ ] [");
        tap_code16(G(KC_RIGHT));

    } else if (leader_sequence_two_keys(KC_X, KC_X)) {         //:q!
      tap_code(KC_ESC);
      SEND_STRING(":q!");

    } else if (leader_sequence_two_keys(KC_Y, KC_Y)) {         //:wq
      tap_code(KC_ESC);
      SEND_STRING(":wq");

    } else if (leader_sequence_two_keys(KC_P, KC_V)) {         // Peter Vassilatos
      SEND_STRING("Peter Vassilatos");

    } else if (leader_sequence_two_keys(KC_U, KC_D)) {         // uvicorn main:app --port 51220 --reload
      SEND_STRING("uvicorn main:app --port 51220 --reload");

    } else if (leader_sequence_two_keys(KC_U, KC_P)) {         // uvicorn main:app --host 0.0.0.0 --port 51220 --reload
      SEND_STRING("uvicorn main:app --host 0.0.0.0 --port 51220 --reload");

    } else if (leader_sequence_two_keys(KC_U, KC_C)) {         // uchicago
      SEND_STRING("uchicago");

    } else if (leader_sequence_three_keys(KC_U, KC_P, KC_C)) { // UChicago
      SEND_STRING("UChicago");

    } else if (leader_sequence_two_keys(KC_M, KC_I)) { // MIDRC
      SEND_STRING("MIDRC");

    } else if (leader_sequence_two_keys(KC_C, KC_H)) { // CHoRUS
       SEND_STRING("CHoRUS");
    }
}
