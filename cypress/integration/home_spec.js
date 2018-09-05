describe('Home view', function() {
  beforeEach(() => {
    cy.visit('/');
  });

  it('should render the home page', () => {
    cy.get('[href*="/"]').should('be.visible');
    cy.get('form').should('be.visible');
    cy.get('[href*="https://reasonml.github.io/"]').should('be.visible');
  });

  it('should navigate to the tracking page when submitting the form', () => {
    cy.get('input').clear();
    cy.get('input').type('navigation-test');
    cy.get('form').submit();
    cy.url().should('include', '/sporing');
  });

  it('should not navigate when the form is empty', () => {
    cy.get('input').clear();
    cy.get('form').submit();
    cy.location('pathname').should('eq', '/');
  });
});
