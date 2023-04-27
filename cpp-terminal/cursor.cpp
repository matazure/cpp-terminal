#include "cpp-terminal/cursor.hpp"

#include "cpp-terminal/input.hpp"

#include <iostream>

Term::Cursor::Cursor(const std::size_t& row, const std::size_t& column) : m_position({row, column}) {}

std::size_t Term::Cursor::row() const { return m_position.first; }

std::size_t Term::Cursor::column() const { return m_position.second; }

bool Term::Cursor::empty()
{
  if(m_position.first == 0 && m_position.second == 0) return true;
  else
    return false;
}

void Term::Cursor::setRow(const std::size_t& row) { m_position.first = row; }

void Term::Cursor::setColum(const std::size_t& column) { m_position.second = column; }

std::string Term::cursor_off() { return "\x1b[?25l"; }

std::string Term::cursor_on() { return "\x1b[?25h"; }

std::string Term::cursor_move(std::size_t row, std::size_t column) { return "\033[" + std::to_string(row) + ';' + std::to_string(column) + 'H'; }

std::string Term::cursor_up(std::size_t rows) { return "\033[" + std::to_string(rows) + 'A'; }

std::string Term::cursor_down(std::size_t rows) { return "\033[" + std::to_string(rows) + 'B'; }

std::string Term::cursor_right(std::size_t columns) { return "\033[" + std::to_string(columns) + 'C'; }

std::string Term::cursor_left(std::size_t columns) { return "\033[" + std::to_string(columns) + 'D'; }

std::string Term::cursor_position_report() { return "\033[6n"; }

std::string Term::clear_eol() { return "\033[K"; }
