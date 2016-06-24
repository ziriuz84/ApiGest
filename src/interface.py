# -*- coding: utf-8 -*-

import urwid


def exit_on_q(key):
    if key in ('q', 'Q'):
        raise urwid.ExitMainLoop()


def item_chosen(button, choice):
    if choice == u"Amministrazione Alveari":
        response = MenuAlveari()
    elif choice == u"Amministrazione Apiari":
        response = MenuApiari()
    else:
        response = MenuPrincipale()
    main.original_widget = response


def menu(title, choices):
    body = [urwid.Text(title), urwid.Divider()]
    for c in choices:
        button = urwid.Button(c)
        urwid.connect_signal(button, 'click', item_chosen, c)
        body.append(urwid.AttrMap(button, None, focus_map='reversed'))
    return urwid.ListBox(urwid.SimpleFocusListWalker(body))


def exit_program(button):
    raise urwid.ExitMainLoop()


def MenuPrincipale():
    global main
    choices = u"Amministrazione Alveari|"
    choices += u"Amministrazione Apiari"
    choices = choices.split("|")
    main = urwid.Padding(menu(u'Menu Principale', choices), left=2, right=2)
    top = urwid.Overlay(main, urwid.SolidFill(u'\N{MEDIUM SHADE}'),
                        align='center', width=('relative', 60),
                        valign='middle', height=('relative', 60),
                        min_width=20, min_height=9)
    return top


def MenuApiari():
    choices = u"Aggiungi Apiario|"
    choices += u"Modifica Apiario|"
    choices += u"Elimina Apiario|"
    choices += u"Torna al Menu Principale"
    choices = choices.split("|")
    main = urwid.Padding(menu(u"Amministrazione Apiari", choices), left=2,
                         right=2)
    top = urwid.Overlay(main, urwid.SolidFill(u'\N{MEDIUM SHADE}'),
                        align='center', width=('relative', 60),
                        valign='middle', height=('relative', 60),
                        min_width=20, min_height=9)
    return top


def MenuAlveari():
    choices = u"Aggiungi Alveare|"
    choices += u"Modifica Alveare|"
    choices += u"Elimina Alveare|"
    choices += u"Torna al Menu Principale"
    choices = choices.split("|")
    main = urwid.Padding(menu(u"Amministrazione Alveare", choices), left=2,
                         right=2)
    top = urwid.Overlay(main, urwid.SolidFill(u'\N{MEDIUM SHADE}'),
                        align='center', width=('relative', 60),
                        valign='middle', height=('relative', 60),
                        min_width=20, min_height=9)
    return top


def Interfaccia():
    headertxt = urwid.Text(u'Apigest 0.1')
    footertxt = urwid.Text(u'Premi q per uscire')
    frame = urwid.Frame(MenuPrincipale(), header=headertxt, footer=footertxt)
    urwid.MainLoop(frame, palette=[('reversed', 'standout', '')],
                   unhandled_input=exit_on_q).run()
